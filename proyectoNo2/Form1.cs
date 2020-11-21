using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace proyectoNo2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Btn_iniciar_Click(object sender, EventArgs e)
        {
            this.Hide();//Se esconde la ventana actual
            //CrearContinuarPartida Iniciar = new CrearContinuarPartida(this); //Se crea una nueva instancia de la ventana del Nivel1 con el nombre "PrimerNivel"
            //Iniciar.Show(); //Se llama y se muestra nivel 1
            Nivel1 _1 = new Nivel1(this);
            _1.Show();

        }
    }
}
