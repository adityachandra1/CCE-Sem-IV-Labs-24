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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        string passwordInput;
        string usernameInput;
        DateTime dob = new DateTime(2015, 12, 08);

        User u1 = new User("Aditya", "Aditya123", "04-01-2002", 500000, "03-23-2021");

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void usernameTxt_TextChanged(object sender, EventArgs e)
        {
            usernameInput = usernameTxt.Text;
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void passwordTxt_TextChanged(object sender, EventArgs e)
        {
            passwordInput = passwordTxt.Text;
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            if (passwordInput == u1.pwd())
            {
                Dashboard frm = new Dashboard(u1);
                frm.Show();
            }
        }

        private void forgotPasswordButton_Click(object sender, EventArgs e)
        {
            Forgot_Password frm = new Forgot_Password(u1);
            frm.Show();
        }
    }
}
