using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Banking_Application
{
    public partial class Forgot_Password : Form
    {
        User user;
        public Forgot_Password(User user)
        {
            InitializeComponent();
            this.user = user;
        }

        string dob_in;
        string pwd_in;
        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            dob_in = dateTimePicker1.Value.ToString();
        }

        private void new_passwordTxt_TextChanged(object sender, EventArgs e)
        {
             pwd_in = new_passwordTxt.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (dob_in == user.DOB)
            {
                user.password = pwd_in;
                MessageBox.Show("Changed Successfully", "Successful", MessageBoxButtons.OK);;
            }
            else
            {
                MessageBox.Show("Wrong DOB", "ERROR", MessageBoxButtons.OK);
            }
        }

    }
}
