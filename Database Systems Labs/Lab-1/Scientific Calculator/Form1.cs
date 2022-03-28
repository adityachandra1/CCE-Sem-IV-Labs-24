using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Scientific_Calculator
{
    public partial class Form1 : Form
    {
        string input = string.Empty;
        string input2 = string.Empty;
        string operand1 = string.Empty;
        string operand2 = string.Empty;
        char operation;
        double result = 0.0;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            input = textBox1.Text;
           // Console.WriteLine(input);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            operand1 = input;
            this.textBox1.Text = "";
            operation = 's';

            double num1;
            double.TryParse(operand1, out num1);
            result = Math.Sqrt(num1);
            textBox1.Text = result.ToString();
            input = string.Empty;
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            operand1 = input;
            this.textBox1.Text = "";
            operation = 'p';
            input = string.Empty;
           
        }

        private void button4_Click(object sender, EventArgs e)
        {
            operand1 = input;
            this.textBox1.Text = "";
            operation = 'i';

            double num1;
            double.TryParse(operand1, out num1);
            result = Math.Pow(num1, -1);
            textBox1.Text = result.ToString();
            input = string.Empty;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            operand1 = input;
            this.textBox1.Text = "";
            operation = 'l';
            input = string.Empty;
           
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            operand2 = input;
            double num1, num2;
            double.TryParse(operand1, out num1);
            double.TryParse(operand2, out num2);

            if (operation == 'p')
            {
                result = Math.Pow(num1, num2);
                textBox1.Text = result.ToString();
            }
            else if (operation == 'l')
            {
                result = Math.Log(num1, num2);
                textBox1.Text = result.ToString();
            }
            else if (operation == 'i')
            {
                result = Math.Pow(num1, -1);
                textBox1.Text = result.ToString();
            }
            else if (operation == 's')
            {
                result = Math.Sqrt(num1);
                textBox1.Text = result.ToString();
            }
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "1";
            this.textBox1.Text += input;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "2";
            this.textBox1.Text += input;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "3";
            this.textBox1.Text += input;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "4";
            this.textBox1.Text += input;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "5";
            this.textBox1.Text += input;
        }

        private void button14_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "6";
            this.textBox1.Text += input;
        }

        private void button13_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "7";
            this.textBox1.Text += input;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "8";
            this.textBox1.Text += input;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "9";
            this.textBox1.Text += input;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = "";
            input += "0";
            this.textBox1.Text += input;
        }
    }
}
