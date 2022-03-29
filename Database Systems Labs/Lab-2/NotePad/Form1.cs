using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Windows;
using System.Drawing.Printing;

namespace NotePad
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Title = "Open";
            dlg.ShowDialog();
            string fName = dlg.FileName;
            StreamReader sr = new StreamReader(fName);
            txtContent.Text = sr.ReadToEnd();
            sr.Close();
        }

        private void txtContent_TextChanged(object sender, EventArgs e)
        {

        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            {
                saveFileDialog1.ShowDialog();
                string fName = saveFileDialog1.FileName;
                StreamWriter sw = new StreamWriter(fName);
                sw.Write(txtContent.Text);
                sw.Flush();
                sw.Close();
            }

        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void fontToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fd = new FontDialog();
            fd.Font = txtContent.SelectionFont;
            fd.Color = txtContent.SelectionColor;
            if (fd.ShowDialog() == DialogResult.OK)
            {
                txtContent.SelectionFont = fd.Font;
                txtContent.SelectionColor = fd.Color;
            }

        }

        private void colorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ColorDialog cd = new ColorDialog();
            cd.Color = txtContent.SelectionColor;
            if (cd.ShowDialog() == DialogResult.OK)
            {
                txtContent.SelectionColor = cd.Color;
            }
        }

        private void aboutUsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult res = MessageBox.Show("Made by Aditya Chandra, 200953032", "About Us", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string message = "Unsaved Work will be lost, Are you sure?";
            string title = "Warning";
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.Yes)
            {
                txtContent.Text ="";
            }
            else
            {
               
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string message = "Unsaved Work will be lost, Are you sure?";
            string title = "Exit";
            MessageBoxButtons buttons = MessageBoxButtons.OKCancel;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.OK)
            {
                this.Close();
            }
            else
            {
                 
            }
        }

        private void printToolStripMenuItem_Click(object sender, EventArgs e)
        {
            printDialog1.ShowDialog();
            printDialog1.AllowSelection = true;
            printDialog1.AllowSomePages = true;
        }
        private void printDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void cutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(txtContent.SelectedText);
            txtContent.SelectedText = string.Empty;
        }

        private void copyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(txtContent.SelectedText);
        }

        private void pasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string xx = Clipboard.GetText();
            txtContent.Text = txtContent.Text.Insert(txtContent.SelectionStart, xx);
        }
    }
}
