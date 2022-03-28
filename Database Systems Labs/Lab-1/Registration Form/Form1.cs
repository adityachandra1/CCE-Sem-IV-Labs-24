using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Registration_Form
{
    public partial class Form1 : Form
    {
        String name = String.Empty;
        String reg = String.Empty;
        DateTime DOB;
        string gender = String.Empty;
        string [] subjects;
        string subs;
        string branch = String.Empty;
        Boolean valid;

        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            name = textBox1.Text;
        }
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            reg = textBox2.Text;
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                gender = radioButton1.Text;
            }
        }
        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked)
            {
                gender = radioButton2.Text;
            }
        }
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            branch = comboBox1.Items[comboBox1.SelectedIndex].ToString();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
             checkedListBox1.SelectedItems.CopyTo(subjects,0);
        }
        private void Form1_Load(object sender, EventArgs e)
        {
        }
        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            DOB = dateTimePicker1.Value;
        }
        private void validate_inputs()
        {
            valid = true;
            if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(reg))
            {
                DialogResult res = MessageBox.Show("Name and Reg. No. fields cannot be empty!", "Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
                valid = false;
            }

            if (int.Parse(reg) <= 0)
            {
                DialogResult res = MessageBox.Show("Reg. No. field cannot be negative!", "Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                valid = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            validate_inputs();
            String text = "Name: " + name +
                "\nRegistration No: " + reg +
                 "\nDOB: " + DOB.ToString() +
                  "\nGender: " + gender +
                   "\n Branch: " + branch;

            MessageBox.Show(text,"Form Submitted", MessageBoxButtons.OK);
        }

 
    }
}
