using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Coffee_Vending_Machine
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        String name;
        String phone;
        String order;
        int token = 1001;
        int item1 = 1;
        int item2 = 2;
        int item3 = 1;
        int item4 = 2;
        int item5 = 1;
        string bill = "";
        bool isAvailable = true;

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged_1(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            name = textBox1.Text;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            phone = textBox2.Text;
        }

        private void radioButton1_CheckedChanged_2(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
            {
                order = radioButton1.Text;
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked)
            {
                order = radioButton2.Text;
            }
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton3.Checked)
            {
                order = radioButton3.Text;
            }
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton4.Checked)
            {
                order = radioButton4.Text;
            }
        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton5.Checked)
            {
                order = radioButton5.Text;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (order == "Espresso")
            {
               
                bill = "100";
                if (item1 <= 0)
                {
                    isAvailable = false;
                }
                item1--;
            }
            else if (order == "Mocha")
            {
                
                bill = "100";
                if (item2 <= 0)
                {
                    isAvailable = false;
                }
                item2--;
            }
            else if (order == "Flat white")
            {
                bill = "95";
                if (item3 <= 0)
                {
                    isAvailable = false;
                }
                item3--;
            }
            else if (order == "Cold Coffee")
            {
                bill = "150";
                if (item4 <= 0)
                {
                    isAvailable = false;
                }
                item4--;
            }
            else if (order == "Americano")
            {
               
                bill = "120";
                if (item5 <= 0)
                {
                    isAvailable = false;
                }
                item5--;
            }

            if (isAvailable == false)
            {
                isAvailable = true;
                MessageBox.Show("Item Out of Stock", "Sorry", MessageBoxButtons.OK);
            }
            else
            {
                string text = "Token Number: " + token +
                           "\nName : " + name +
                           "\nPhone Number : " + phone +
                           "\nOrder : " + order +
                           "\nTotal Bill : " + bill;
                token++;
                MessageBox.Show(text, "Receipt", MessageBoxButtons.OK);
            }

           
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

  
    }
}
