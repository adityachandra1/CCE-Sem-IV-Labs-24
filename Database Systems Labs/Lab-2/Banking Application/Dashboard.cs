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
    public partial class Dashboard : Form
    {
        User user;
        public Dashboard(User user)
        {
            InitializeComponent();
            this.user = user;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Transfer_Form frm = new Transfer_Form();
            frm.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void username_lbl_Click(object sender, EventArgs e)
        {
            username_lbl.Text = user.name;
        }

        private void balance_lbl_Click(object sender, EventArgs e)
        {
            balance_lbl.Text = user.balance.ToString();
        }

        private void last_accessed_lbl_Click(object sender, EventArgs e)
        {
            last_accessed_lbl.Text = user.lastAccessed;
        }

    }
}
