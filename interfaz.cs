using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MiInterfazUART
{
    public partial class Form1 : Form
    {

        int flag = 0, tiempo = 0, pulsa = 0;
        String lectura, PPM = "Calculando pulso...";

        public Form1()
        {
            InitializeComponent();
            try
            {
                foreach(String s in System.IO.Ports.SerialPort.GetPortNames())
                {
                    comboBox1.Items.Add(s);
                }
            }catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {
            
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if(flag == 1)
            {
                if (checkBox1.Checked)
                {
                    serialPort1.Write("1");
                }
                else
                {
                    serialPort1.Write("2");

                }
            }
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (flag == 1)
            {
                if (checkBox2.Checked)
                {
                    serialPort1.Write("3");
                }
                else
                {
                    serialPort1.Write("4");

                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (flag == 1)
            {
                
                    label6.Text = PPM;
                
                serialPort1.Write("9");
                 tiempo++;

                 if(tiempo == 50)
                 {
                     tiempo = 0;
                     chart1.Series[0].Points.Clear();
                 }

                    label5.Text = Convert.ToString(pulsa);

                    chart1.Series["Voltaje"].Points.AddY(pulsa);
                


            }
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            if(flag == 1)
            {
                lectura = serialPort1.ReadLine();

                if (lectura.StartsWith("PPM"))
                {
                    PPM = lectura;
                }
                else
                {
                    double temporal = Convert.ToDouble(lectura);
                    pulsa = Convert.ToInt32(temporal);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            button2.Enabled = false;
            checkBox1.Enabled = false;
            checkBox2.Enabled = false;
            chart1.Titles.Add("Gráfica voltaje");
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            flag = 1;
            serialPort1.PortName = comboBox1.Text;
            serialPort1.Open();
            button1.Enabled = false;
            button2.Enabled = true;
            checkBox1.Enabled = true;
            checkBox2.Enabled = true;

            label4.Text = "Conectado";
            label6.Text = "Calculando pulsos...";

            chart1.Series[0].Points.Clear();
            tiempo = 0;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            flag = 2;
            button1.Enabled = true;
            button2.Enabled = false;
            checkBox1.Enabled = false;
            checkBox2.Enabled = false;

            label4.Text = "Desconectado";

            serialPort1.Write("2");
            serialPort1.Write("4");
            serialPort1.Close();

        }
    }
}
