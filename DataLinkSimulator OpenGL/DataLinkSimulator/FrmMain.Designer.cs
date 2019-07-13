namespace DataLinkSimulator
{
    partial class FrmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.LBx_Sender = new System.Windows.Forms.ListBox();
            this.lbl_sender = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.LBx_Receiver = new System.Windows.Forms.ListBox();
            this.lbl_receiver = new System.Windows.Forms.Label();
            this.btn_Send = new System.Windows.Forms.Button();
            this.rb_stp_wait = new System.Windows.Forms.RadioButton();
            this.rb_Selective_Repeat = new System.Windows.Forms.RadioButton();
            this.rb_goback_N = new System.Windows.Forms.RadioButton();
            this.grpbox_win_size = new System.Windows.Forms.GroupBox();
            this.num_win_size = new System.Windows.Forms.NumericUpDown();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txt_Timeout = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.simpleOpenGlControl1 = new Tao.Platform.Windows.SimpleOpenGlControl();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.lbl_TimeElapsed = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.btn_Inc = new System.Windows.Forms.Button();
            this.btn_Dec = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnReset = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.LBx_Log = new System.Windows.Forms.ListBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.grpbox_win_size.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_win_size)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // LBx_Sender
            // 
            this.LBx_Sender.FormattingEnabled = true;
            this.LBx_Sender.Location = new System.Drawing.Point(38, 47);
            this.LBx_Sender.Name = "LBx_Sender";
            this.LBx_Sender.Size = new System.Drawing.Size(114, 134);
            this.LBx_Sender.TabIndex = 0;
            // 
            // lbl_sender
            // 
            this.lbl_sender.AutoSize = true;
            this.lbl_sender.Location = new System.Drawing.Point(6, 16);
            this.lbl_sender.Name = "lbl_sender";
            this.lbl_sender.Size = new System.Drawing.Size(38, 13);
            this.lbl_sender.TabIndex = 2;
            this.lbl_sender.Text = "Ready";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.LBx_Sender);
            this.groupBox1.Controls.Add(this.lbl_sender);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Left;
            this.groupBox1.Location = new System.Drawing.Point(3, 16);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 191);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Sender";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.LBx_Receiver);
            this.groupBox2.Controls.Add(this.lbl_receiver);
            this.groupBox2.Dock = System.Windows.Forms.DockStyle.Right;
            this.groupBox2.Location = new System.Drawing.Point(373, 16);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 191);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Receiver";
            // 
            // LBx_Receiver
            // 
            this.LBx_Receiver.FormattingEnabled = true;
            this.LBx_Receiver.Location = new System.Drawing.Point(38, 47);
            this.LBx_Receiver.Name = "LBx_Receiver";
            this.LBx_Receiver.Size = new System.Drawing.Size(114, 134);
            this.LBx_Receiver.TabIndex = 0;
            // 
            // lbl_receiver
            // 
            this.lbl_receiver.AutoSize = true;
            this.lbl_receiver.Location = new System.Drawing.Point(18, 16);
            this.lbl_receiver.Name = "lbl_receiver";
            this.lbl_receiver.Size = new System.Drawing.Size(38, 13);
            this.lbl_receiver.TabIndex = 2;
            this.lbl_receiver.Text = "Ready";
            // 
            // btn_Send
            // 
            this.btn_Send.Location = new System.Drawing.Point(258, 345);
            this.btn_Send.Name = "btn_Send";
            this.btn_Send.Size = new System.Drawing.Size(84, 34);
            this.btn_Send.TabIndex = 5;
            this.btn_Send.Text = "S&end";
            this.btn_Send.UseVisualStyleBackColor = true;
            this.btn_Send.Click += new System.EventHandler(this.btn_Send_Click);
            // 
            // rb_stp_wait
            // 
            this.rb_stp_wait.AutoSize = true;
            this.rb_stp_wait.Checked = true;
            this.rb_stp_wait.Location = new System.Drawing.Point(21, 29);
            this.rb_stp_wait.Name = "rb_stp_wait";
            this.rb_stp_wait.Size = new System.Drawing.Size(93, 17);
            this.rb_stp_wait.TabIndex = 6;
            this.rb_stp_wait.TabStop = true;
            this.rb_stp_wait.Text = "Stop and Wait\r\n";
            this.rb_stp_wait.UseVisualStyleBackColor = true;
            this.rb_stp_wait.CheckedChanged += new System.EventHandler(this.rb_stp_wait_CheckedChanged);
            // 
            // rb_Selective_Repeat
            // 
            this.rb_Selective_Repeat.AutoSize = true;
            this.rb_Selective_Repeat.Location = new System.Drawing.Point(299, 29);
            this.rb_Selective_Repeat.Name = "rb_Selective_Repeat";
            this.rb_Selective_Repeat.Size = new System.Drawing.Size(107, 17);
            this.rb_Selective_Repeat.TabIndex = 7;
            this.rb_Selective_Repeat.Text = "Selective Repeat";
            this.rb_Selective_Repeat.UseVisualStyleBackColor = true;
            this.rb_Selective_Repeat.CheckedChanged += new System.EventHandler(this.rb_stp_wait_CheckedChanged);
            // 
            // rb_goback_N
            // 
            this.rb_goback_N.AutoSize = true;
            this.rb_goback_N.Location = new System.Drawing.Point(171, 29);
            this.rb_goback_N.Name = "rb_goback_N";
            this.rb_goback_N.Size = new System.Drawing.Size(78, 17);
            this.rb_goback_N.TabIndex = 8;
            this.rb_goback_N.Text = "Go Back N";
            this.rb_goback_N.UseVisualStyleBackColor = true;
            this.rb_goback_N.CheckedChanged += new System.EventHandler(this.rb_stp_wait_CheckedChanged);
            // 
            // grpbox_win_size
            // 
            this.grpbox_win_size.Controls.Add(this.num_win_size);
            this.grpbox_win_size.Location = new System.Drawing.Point(258, 69);
            this.grpbox_win_size.Name = "grpbox_win_size";
            this.grpbox_win_size.Size = new System.Drawing.Size(84, 44);
            this.grpbox_win_size.TabIndex = 9;
            this.grpbox_win_size.TabStop = false;
            this.grpbox_win_size.Text = "Window Size";
            this.grpbox_win_size.Visible = false;
            // 
            // num_win_size
            // 
            this.num_win_size.Location = new System.Drawing.Point(21, 16);
            this.num_win_size.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.num_win_size.Minimum = new decimal(new int[] {
            2,
            0,
            0,
            0});
            this.num_win_size.Name = "num_win_size";
            this.num_win_size.Size = new System.Drawing.Size(40, 20);
            this.num_win_size.TabIndex = 0;
            this.num_win_size.Value = new decimal(new int[] {
            2,
            0,
            0,
            0});
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.rb_stp_wait);
            this.groupBox3.Controls.Add(this.rb_Selective_Repeat);
            this.groupBox3.Controls.Add(this.rb_goback_N);
            this.groupBox3.Location = new System.Drawing.Point(94, 11);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(412, 52);
            this.groupBox3.TabIndex = 10;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Flow Control Techniques";
            // 
            // txt_Timeout
            // 
            this.txt_Timeout.Location = new System.Drawing.Point(471, 430);
            this.txt_Timeout.Name = "txt_Timeout";
            this.txt_Timeout.Size = new System.Drawing.Size(24, 20);
            this.txt_Timeout.TabIndex = 16;
            this.txt_Timeout.Text = "3";
            this.txt_Timeout.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_R_Min_KeyPress);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(420, 433);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(45, 13);
            this.label3.TabIndex = 15;
            this.label3.Text = "Timeout";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.simpleOpenGlControl1);
            this.groupBox4.Controls.Add(this.groupBox1);
            this.groupBox4.Controls.Add(this.groupBox2);
            this.groupBox4.Location = new System.Drawing.Point(12, 119);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(576, 210);
            this.groupBox4.TabIndex = 17;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Transfer";
            // 
            // simpleOpenGlControl1
            // 
            this.simpleOpenGlControl1.AccumBits = ((byte)(0));
            this.simpleOpenGlControl1.AutoCheckErrors = false;
            this.simpleOpenGlControl1.AutoFinish = false;
            this.simpleOpenGlControl1.AutoMakeCurrent = true;
            this.simpleOpenGlControl1.AutoSwapBuffers = true;
            this.simpleOpenGlControl1.BackColor = System.Drawing.Color.Black;
            this.simpleOpenGlControl1.ColorBits = ((byte)(32));
            this.simpleOpenGlControl1.DepthBits = ((byte)(16));
            this.simpleOpenGlControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.simpleOpenGlControl1.Location = new System.Drawing.Point(203, 16);
            this.simpleOpenGlControl1.Name = "simpleOpenGlControl1";
            this.simpleOpenGlControl1.Size = new System.Drawing.Size(170, 191);
            this.simpleOpenGlControl1.StencilBits = ((byte)(0));
            this.simpleOpenGlControl1.TabIndex = 5;
            this.simpleOpenGlControl1.Visible = false;
            this.simpleOpenGlControl1.Paint += new System.Windows.Forms.PaintEventHandler(this.simpleOpenGlControl1_Paint);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // lbl_TimeElapsed
            // 
            this.lbl_TimeElapsed.AutoSize = true;
            this.lbl_TimeElapsed.Location = new System.Drawing.Point(495, 337);
            this.lbl_TimeElapsed.Name = "lbl_TimeElapsed";
            this.lbl_TimeElapsed.Size = new System.Drawing.Size(0, 13);
            this.lbl_TimeElapsed.TabIndex = 18;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(424, 337);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 13);
            this.label5.TabIndex = 19;
            this.label5.Text = "Time elapsed";
            // 
            // btn_Inc
            // 
            this.btn_Inc.Location = new System.Drawing.Point(20, 17);
            this.btn_Inc.Name = "btn_Inc";
            this.btn_Inc.Size = new System.Drawing.Size(47, 23);
            this.btn_Inc.TabIndex = 20;
            this.btn_Inc.Text = "&Faster";
            this.btn_Inc.UseVisualStyleBackColor = true;
            this.btn_Inc.Click += new System.EventHandler(this.btn_Inc_Click);
            // 
            // btn_Dec
            // 
            this.btn_Dec.Location = new System.Drawing.Point(20, 44);
            this.btn_Dec.Name = "btn_Dec";
            this.btn_Dec.Size = new System.Drawing.Size(47, 23);
            this.btn_Dec.TabIndex = 21;
            this.btn_Dec.Text = "&Slower";
            this.btn_Dec.UseVisualStyleBackColor = true;
            this.btn_Dec.Click += new System.EventHandler(this.btn_Dec_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(501, 433);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "seconds";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btn_Inc);
            this.groupBox5.Controls.Add(this.btn_Dec);
            this.groupBox5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox5.Location = new System.Drawing.Point(427, 353);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(79, 73);
            this.groupBox5.TabIndex = 23;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Speed";
            // 
            // btnReset
            // 
            this.btnReset.Location = new System.Drawing.Point(270, 400);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(61, 26);
            this.btnReset.TabIndex = 24;
            this.btnReset.Text = "&Reset";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.LBx_Log);
            this.groupBox6.Location = new System.Drawing.Point(15, 345);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(200, 100);
            this.groupBox6.TabIndex = 25;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Log";
            // 
            // LBx_Log
            // 
            this.LBx_Log.Dock = System.Windows.Forms.DockStyle.Fill;
            this.LBx_Log.FormattingEnabled = true;
            this.LBx_Log.Location = new System.Drawing.Point(3, 16);
            this.LBx_Log.Name = "LBx_Log";
            this.LBx_Log.Size = new System.Drawing.Size(194, 69);
            this.LBx_Log.TabIndex = 1;
            // 
            // FrmMain
            // 
            this.AcceptButton = this.btn_Send;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(600, 456);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.lbl_TimeElapsed);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.txt_Timeout);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.grpbox_win_size);
            this.Controls.Add(this.btn_Send);
            this.Controls.Add(this.groupBox5);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "FrmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Data Link Simulator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.grpbox_win_size.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.num_win_size)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox LBx_Sender;
        private System.Windows.Forms.Label lbl_sender;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.ListBox LBx_Receiver;
        private System.Windows.Forms.Label lbl_receiver;
        private System.Windows.Forms.Button btn_Send;
        private System.Windows.Forms.RadioButton rb_stp_wait;
        private System.Windows.Forms.RadioButton rb_Selective_Repeat;
        private System.Windows.Forms.RadioButton rb_goback_N;
        private System.Windows.Forms.GroupBox grpbox_win_size;
        private System.Windows.Forms.NumericUpDown num_win_size;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox txt_Timeout;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Timer timer1;
        public Tao.Platform.Windows.SimpleOpenGlControl simpleOpenGlControl1;
        private System.Windows.Forms.Label lbl_TimeElapsed;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button btn_Inc;
        private System.Windows.Forms.Button btn_Dec;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.ListBox LBx_Log;
    }
}

