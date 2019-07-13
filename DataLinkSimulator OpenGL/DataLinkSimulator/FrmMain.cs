using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Tao.FreeGlut;
using Tao.OpenGl;
using Tao.Platform.Windows;
namespace DataLinkSimulator
{
    public partial class FrmMain : Form
    {
        #region Variables
        int nwidth, nheight;
        int nwin_size = 0;
        double[] color_Blue = { 0, 0, 1 };//frame
        double[] color_yellow = { 1, 1, 0 };//ack
        double dtimeout, dlen = 10;
        float fspeed = 6;
        bool bsend_file = true;
        bool bcontinue_receive = true;
        DateTime dtstart;        
        Queue Q_Acks = new Queue();
        Queue Q_Frames = new Queue();
        clssSqaure objFrame, objAck;
        List<clssSqaure> lst_clssSqaure = new List<clssSqaure>();
        object objselected_frame_stp_wt;
        #endregion

        public FrmMain()
        {
            InitializeComponent();
        }

        private void btn_Send_Click(object sender, EventArgs e)
        {
            #region Initialization
            lst_clssSqaure.Clear();
            objFrame = new clssSqaure(10 - nwidth, 20, 1, color_Blue);
            lst_clssSqaure.Add(objFrame);
            bsend_file = true;
            dtstart = DateTime.Now;
            if (txt_Timeout.Text != string.Empty)
                dtimeout = int.Parse(txt_Timeout.Text);
            else
                dtimeout = 3;//default value
            #endregion
            if (rb_stp_wait.Checked)
            {
                if (LBx_Sender.SelectedIndex < 0)
                {
                    MessageBox.Show("please select frame to send", "Info", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                objselected_frame_stp_wt = LBx_Sender.SelectedItem;
            }
            else
            {
                if (!bcontinue_receive)
                {
                    bcontinue_receive = true;
                }

                //modify window size to the count of remaining items
                nwin_size = Convert.ToInt32(num_win_size.Value);
                if (nwin_size > LBx_Sender.Items.Count)
                    nwin_size = LBx_Sender.Items.Count;
                for (int i = 0; i < nwin_size; i++)
                {
                    Q_Frames.Enqueue(LBx_Sender.Items[i]);
                }
            }
            timer1.Enabled = simpleOpenGlControl1.Visible = true;
        }

        private void rb_stp_wait_CheckedChanged(object sender, EventArgs e)
        {
            grpbox_win_size.Visible = (!rb_stp_wait.Checked) ? true : false;
        }

        private void txt_R_Min_KeyPress(object sender, KeyPressEventArgs e)
        {
            //numbers only
            e.Handled = !char.IsDigit(e.KeyChar) && e.KeyChar != (char)Keys.Back;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            simpleOpenGlControl1.InitializeContexts();
            simpleOpenGlControl1.AutoSwapBuffers = true;
            nwidth = simpleOpenGlControl1.Width / 2;
            nheight = simpleOpenGlControl1.Height / 2;
            initializeGraphix();
            Reset();
        }

        private void initializeGraphix()
        {
            Gl.glMatrixMode(Gl.GL_PROJECTION);
            Gl.glLoadIdentity();
            Glu.gluOrtho2D(-nwidth, nwidth, -nheight, nheight);
            Gl.glClearColor(0, 0, 0, 1);
            Gl.glMatrixMode(Gl.GL_MODELVIEW);
            Gl.glLoadIdentity();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            simpleOpenGlControl1.Invalidate();
        }

        private void simpleOpenGlControl1_Paint(object sender, PaintEventArgs e)
        {
            Gl.glClear(Gl.GL_COLOR_BUFFER_BIT);
            Gl.glLoadIdentity();
            foreach (clssSqaure objclssSqaure in lst_clssSqaure)
            {
                objclssSqaure.Move();
            }
            transform();
            Gl.glFlush();
        }

        private void transform()
        {
            TimeSpan tsSend_Time = DateTime.Now - dtstart;
            lbl_TimeElapsed.Text = tsSend_Time.ToString();
           
            if (rb_stp_wait.Checked)
            {
                #region Stop & Wait
                #region Explanation
                /*
                     * Stop after Transmitting a Frame
                     * Wait for an Acknowledgement
                     * 
                     * 
                     * Tx                   Rx
                     * 
                     * Frame_0
                     * |------------------->|
                     * |                    |
                     * |                 Ack|         
                     * |<-------------------|
                     * |                    | 
                     * |                    |
                     * |Frame_1             |
                     * |---------->         |
                     * |             Timeout|
                     * |                NAck|         
                     * |<-------------------|
                     * |                    | 
                     * |                    |
                     * Frame_2
                     * |------------------->|
                     * |                    |
                     * |                 Ack|         
                     * |         <----------|
                     * |                    | 
                     * |Timeout             |
                     */
                #endregion
                if (objselected_frame_stp_wt != null)
                {
                    if (tsSend_Time.Seconds > dtimeout)//send time exceeded predetermined timeout
                    {
                        if (bsend_file) //Rx didnt receive Frame
                            lbl_receiver.Text = "Timeout";

                        else            //Tx didnt receive Acknowledgment
                            lbl_sender.Text = "Timeout";

                        timer1.Enabled = false;//stop sending
                    }

                    if (bsend_file)//Frame is being sent to Rx
                    {
                        if (LBx_Receiver.Items.Contains(objselected_frame_stp_wt))
                            lbl_sender.Text = "Resending " + objselected_frame_stp_wt.ToString();
                        else
                            lbl_sender.Text = "Sending " + objselected_frame_stp_wt.ToString();

                        if ((objFrame.Fxpos + dlen) > nwidth)//frame arrived to Rx
                        {
                            if (!LBx_Receiver.Items.Contains(objselected_frame_stp_wt))
                            {
                                LBx_Receiver.Items.Add(objselected_frame_stp_wt);
                            }
                            lbl_sender.Text = "awaiting acknowledgement";
                            lbl_receiver.Text = "sending acknowledgement";
                            bsend_file = false;
                            dtstart = DateTime.Now;
                            objAck = new clssSqaure(nwidth, -20, -1, color_yellow);
                            lst_clssSqaure.Add(objAck);
                        }
                        objFrame.Fxpos += fspeed * objFrame.Fvec_X;
                    }
                    else//Ack is being sent to Tx
                    {
                        if (((objAck.Fxpos - dlen + 10) < (nwidth * -1)))//Ack arrived to Tx
                        {
                            lbl_sender.Text = "Acknowledgement received";
                            if (LBx_Receiver.Items.Contains(objselected_frame_stp_wt))
                            {
                                LBx_Sender.Items.Remove(objselected_frame_stp_wt);
                            }
                            timer1.Enabled = false;
                            bsend_file = true;
                        }
                        objAck.Fxpos += fspeed * objAck.Fvec_X;
                    }
                }
                #endregion
            }
            else if (rb_goback_N.Checked)
            {
                #region Go Back N
                #region Explanation
                /*
                 * the sending process continues to send a number of frames specified by 
                 * a window size without waiting for the ACK packet from the receiver.
         
                 * if any frame was lost or damaged, or the ACK acknowledging them was lost or damaged,
                 * then that frame and all following frames in the window
                 * (even if they were received without error) will be re-sent.
                 */
                #endregion
                SlidingWindow(tsSend_Time, true  /*Is it GoBackN*/);
                
                #endregion
            }
            else
            {
                #region Selective Repeat
                #region Explanation
                /* The sending process continues to send a number of frames specified by a window size even after a frame loss.
                 * Unlike Go-Back-N ARQ, the receiving process will continue to accept and acknowledge frames sent after an initial
                 * error.
                 * Only faulted frames will be resent.
                 * */
                #endregion
                SlidingWindow(tsSend_Time, false /*Is it GoBackN*/);
                #endregion
            }
        }

        private void SlidingWindow(TimeSpan tsSend_Time, bool bIsGoBackN)
        {
            object[] arr_Frames = Q_Frames.ToArray();
            if (Q_Frames.Count != 0)//Sending Frames
            {
                objFrame.Fxpos += fspeed * objFrame.Fvec_X;
                lbl_sender.Text = "Sending " + arr_Frames[0].ToString();
                lbl_receiver.Text = "Receiving " + arr_Frames[0].ToString();

                if (objFrame.Fxpos + dlen > nwidth)//frame reached Rx
                {
                    object Objreceivedframe = Q_Frames.Dequeue();
                    if (tsSend_Time.Seconds < dtimeout) //within time
                    {
                        if (bcontinue_receive)//sending was not interrupted,receive frames normally
                        {
                            LBx_Receiver.Items.Add(Objreceivedframe);
                            LBx_Log.Items.Add(Objreceivedframe.ToString() + " received");
                            Q_Acks.Enqueue(Objreceivedframe);

                            objAck = new clssSqaure(nwidth, -20, -1, color_yellow);//Send Ack
                            lst_clssSqaure.Add(objAck);
                        }
                    }
                    else//frame exceeded time
                    {
                        LBx_Log.Items.Add(Objreceivedframe.ToString() + " timed out");
                        if (bIsGoBackN && bcontinue_receive)
                        {
                            LBx_Log.Items.Add("Rx stopped receiving");
                            bcontinue_receive = false;//stop receiving
                        }
                    }
                    dtstart = DateTime.Now; //reset time
                    objFrame.Fxpos = 10 - nwidth; //reset Frame position
                }

            }
            if (Q_Acks.Count != 0)//Sending Ack
            {
                objAck.Fxpos += fspeed * 2 * objAck.Fvec_X;
                if (((objAck.Fxpos - dlen + 10) < (nwidth * -1)))//Ack arrived to Tx
                {
                    LBx_Log.Items.Add("Ack received");
                    LBx_Sender.Items.Remove(Q_Acks.Dequeue());
                    lst_clssSqaure.Remove(objAck);
                }
            }
            if (Q_Frames.Count == 0 && Q_Acks.Count == 0)
            {
                lbl_receiver.Text = lbl_sender.Text = "Ready";
                lbl_TimeElapsed.Text = string.Empty;
            }
        }

        private void btn_Dec_Click(object sender, EventArgs e)
        {
            if (fspeed - 2 > 0)
                fspeed -= 2;
        }

        private void btn_Inc_Click(object sender, EventArgs e)
        {
            fspeed += 2;
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            Reset();
        }

        private void Reset()
        {
            LBx_Sender.Items.Clear();
            LBx_Receiver.Items.Clear();
            LBx_Log.Items.Clear();
            lst_clssSqaure.Clear();
            Q_Acks.Clear();
            Q_Frames.Clear();
            lbl_TimeElapsed.Text = string.Empty;
            timer1.Enabled = false;
            fspeed = 6;
            for (int i = 1 ; i < 11; i++)
            {
                LBx_Sender.Items.Add("Frame " + i);
            }
            lbl_receiver.Text = lbl_sender.Text = "Ready";
        }
    }
}
