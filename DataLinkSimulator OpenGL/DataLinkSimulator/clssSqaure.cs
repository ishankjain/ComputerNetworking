using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Tao.OpenGl;

namespace DataLinkSimulator
{
    class clssSqaure
    {
        float fxpos, fypos, fvec_X;
        double[] Square_Color;
        public clssSqaure(float fxpos, float fypos,float fvec_X, double[] Square_Color)
        {
            this.fxpos = fxpos;
            this.fypos = fypos;
            this.fvec_X = fvec_X;
            this.Square_Color = Square_Color;
        }
        public void Move()
        {
            Gl.glTranslatef(fxpos, fypos, 0);
            DrawSquare();
            Gl.glLoadIdentity();
        }
        public float Fxpos
        {
            get { return fxpos; }
            set { fxpos = value; }
        }
        public float Fvec_X
        {
            get { return fvec_X; }
        }
        private void DrawSquare()
        {
            Gl.glBegin(Gl.GL_QUADS);

            Gl.glColor3dv(Square_Color);
            Gl.glVertex2d(10, 10);
            Gl.glVertex2d(-10, 10);
            Gl.glVertex2d(-10, -10);
            Gl.glVertex2d(10, -10);

            Gl.glEnd();
        }

    }
}
