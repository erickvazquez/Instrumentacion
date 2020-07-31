using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace InterfazPulsoCardiaco
{
	public partial class Form1 : Form
	{
		int flag = 0;
		int fl = 0;
		int fl2 = 0;
		int tiempo = 0;
		int pulsa = 0;
		int PPM=0;
		String lectura;
		int PulsosContados=0;

		public Form1()
		{
			InitializeComponent();

			try
            {
				foreach (String s in System.IO.Ports.SerialPort.GetPortNames())
				{
					comboBox1.Items.Add(s);
				}
            }catch(Exception ex)
            {
				MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
		}

		private void button1_Click(object sender, EventArgs e)
		{
			//Bandera en uno indicando conectar
			flag = 1;
			serialPort1.PortName = comboBox1.Text;
			serialPort1.Open();
			button1.Enabled = false;
			button2.Enabled = true;

			label3.Text = "Conectado";
			chart1.Series[0].Points.Clear();
			tiempo = 0;
		}

		private void label1_Click(object sender, EventArgs e)
		{

		}

		private void label2_Click(object sender, EventArgs e)
		{

		}

		private void timer1_Tick(object sender, EventArgs e)
		{ 
			//Pic conectadod
			if(flag==1)
            {
				serialPort1.Write("9");
				tiempo++;
				
				if(pulsa==5 & fl==0)
				{ 
					PulsosContados++;
					fl = 1;
				}
				if (pulsa == 0)
					fl = 0;

				if(fl2==1)
                {
					fl2 = 0;
					label6.Text = PPM + "";

				}

				if(tiempo==51)
                {
					tiempo = 0;
					chart1.Series[0].Points.Clear();
					//0label8.Text = PulsosContados+"";
					PulsosContados = 0;
                }
				
				label5.Text = pulsa + "";
				chart1.Series["Voltaje"].Points.AddY(pulsa);
            }
		}

		private void button2_Click(object sender, EventArgs e)
		{
			//Bandera en dos indicando desconeccion
			flag = 2;

			button1.Enabled = true;
			button2.Enabled = false;

			label3.Text = "Desconectado";
			serialPort1.Close();

		}

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
			if (flag == 1)
			{
				try
				{
					lectura = serialPort1.ReadLine();

					if (lectura.StartsWith("PPM"))
					{
						String ParteValor = lectura.Substring(4);
						PPM = Convert.ToInt32(ParteValor);
						fl2 = 1;
					}
                    else 
					{
						double temporal = Convert.ToDouble(lectura);

						pulsa = Convert.ToInt32(temporal);
					}
				}catch(Exception ex)
                {
					MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
				}
			

				

			}
        }

        private void Form1_Load(object sender, EventArgs e)
        {
			chart1.Titles.Add("Grafica de voltaje");
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
			label5.Text=pulsa+"";
        }

        private void button3_Click_1(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click_1(object sender, EventArgs e)
        {

        }
    }
}
