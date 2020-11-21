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
    public partial class CrearContinuarPartida : Form
    {
        Form1 formpapa;
        public CrearContinuarPartida(Form1 form)
        {
            InitializeComponent();
            formpapa = form;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void Btn_top10_Click(object sender, EventArgs e)
        {

        }

        private void Btn_crearpartida_Click(object sender, EventArgs e)
        {
            this.Hide();//Se esconde la ventana actual
            Nivel1 PrimerNivel = new Nivel1(formpapa); //Se crea una nueva instancia de la ventana del Nivel1 con el nombre "PrimerNivel"
            PrimerNivel.Show(); //Se llama y se muestra nivel 1         

        }

        private void CrearContinuarPartida_FormClosed(object sender, FormClosedEventArgs e)
        {
            formpapa.Close();
        }
    }
}
