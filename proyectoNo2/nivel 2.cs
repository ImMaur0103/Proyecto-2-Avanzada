using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace proyectoNo2
{
    public partial class nivel_2 : Form
    {
        int[,] matrizposiciones = new int[30, 30];
        
        int[] callesnivel2 = new int[10];
        int[] tipocarro = new int[5];

        bool win = false;
        //puntaje del juego       
        int puntaje = 0;
        //tiempo del nivel
        int segundosnivel2 = 30;
        //tiempo jugado
        int segundosjugados = 0;
        //posiciones del personaje cuando inicia el nivel
        int personajex = 0;
        int personajey = 0;
        const int principal = 0;
        const int carroamarillo = 1;
        const int carroazul = 2;
        const int carroverde = 3;
        const int carrorojo = 4;
        const int carronegro = 5;
        const int calle = 6;
        const int grama = 7;
        const int anciano = 8;
        const int mascota = 9;
        const int agente = 10;
        const int crosswalk = 11;
        const int semafororojo = 12;
        const int semaforoverde = 13;
        const int principalconmascota = 14;
        const int principalconanciano = 15;
        const int atropellado = 16;
        const int negro = 17;
        int limitex = 29;


        Form1 form1;
        public nivel_2(Form1 obj)
        {
            InitializeComponent();
            form1 = obj;
            this.KeyPreview = true;
            callesnivel2[0] = 1;
            callesnivel2[1] = 2;
            callesnivel2[2] = 3;
            callesnivel2[3] = 5;
            callesnivel2[4] = 6;
            callesnivel2[5] = 7;
            callesnivel2[6] = 8;
            callesnivel2[7] = 10;
            callesnivel2[8] = 11;
            callesnivel2[9] = 12;
            //Vector en el que cada posición guarda el tipo de carro que se usará en el nivel

            tipocarro[0] = carroamarillo;
            tipocarro[1] = carroazul;
            tipocarro[2] = carroverde;
            tipocarro[3] = carrorojo;
            tipocarro[4] = carronegro;
        }
        private void nivel_2_Load(object sender, EventArgs e)
        {
            StreamReader sr = new StreamReader("Nivel2.txt");
            int fila = 0; //variable fila que ayuda a cargar lo del arcivo de texto al DataGridView y a la matriz
            int columnas = 0; //variable fila que ayuda a cargar lo del arcivo de texto al DataGridView y a la matriz
            while (sr.EndOfStream == false) //Mientras no haya terminado de leer el archivo
            {
                string line = sr.ReadLine();
                string[] split = line.Split(',');//vector que lee lo que esta en el archivo separado por comas
                Dgv_tablero.Rows.Add();
                columnas = split.Count();

                for (int columna = 0; columna < split.Count(); columna++) //Se repite el ciclo mientras haya líneas que leer en el archivo
                {
                    int numero = int.Parse(split[columna]); //Cada número que lee en las líneas del archivo lo guarda en la variable numero
                    Dgv_tablero[columna, fila].Value = imageList2.Images[numero]; //En la matriz se muestra la imagen que corresponde a ese número
                    matrizposiciones[fila, columna] = numero; //En la matriz se guarda en cada posicion el número en cada línea y columna del archivo
                }
                fila++; //fila aumenta para poder pasar a la siguiente línea en el archivo
            }
            for (int i = 0; i < columnas; i++)
            {
                //cambia el ancho de las celdas del datagrid
                Dgv_tablero.Columns[i].Width = 40;
            }
            for (int i = 0; i < fila; i++)
            {
                //cambia la altura de las celdas del datagrid
                //Dgv_tablero.Rows[i].Height = 40;
            }
            sr.Close(); //Deja de leer el archivo
            //Se activa el timer que controla los carros y el que controla el tiempo de juego
            timer1.Enabled = true;
        }
        private void nivel_2_FormClosed(object sender, FormClosedEventArgs e)
        {
            form1.Close();
        }


        private void Dgv_tablero_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        private void Dgv_tablero_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        public void movercarro(Carro carro)
        {
            int siguiente = 0;
            switch (carro.tipocarro)
            {
                case carroazul: //Si se obtiene carro azul, aparecerá un carro con las siguientes validaciones:
                    {
                        if (carro.posx < limitex)
                        {
                            if (carro.posx != 29)
                            {
                                siguiente = matrizposiciones[carro.posy, carro.posx + 1];
                            }
                            if (siguiente == principal)
                            {
                                //se restan los puntos (la funcion regresa negativos)
                                puntaje += carro.choque(false);
                                label1.Text = "Puntaje: " + puntaje.ToString();
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[atropellado];
                                matrizposiciones[personajey, personajex] = atropellado;
                                if (carro.posx < limitex - 2)
                                {
                                    siguiente = matrizposiciones[carro.posy, carro.posx + 2];
                                    if (siguiente == calle)
                                    {
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                        matrizposiciones[carro.posy, carro.posx] = calle;
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[carro.tipocarro];
                                        matrizposiciones[carro.posy, carro.posx + 2] = carro.tipocarro;
                                    }
                                    else if (siguiente == semaforoverde)
                                    {

                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                        matrizposiciones[carro.posy, carro.posx] = calle;
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[semaforoverde];
                                        matrizposiciones[carro.posy, carro.posx + 2] = semaforoverde;
                                    }


                                }

                            }
                            else if (carro.posx == 28)
                            {
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                            }
                            else if (siguiente == calle)
                            {

                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 1].Value = imageList2.Images[carro.tipocarro];
                                matrizposiciones[carro.posy, carro.posx + 1] = carro.tipocarro;
                            }
                        }
                    }
                    break;
                case carronegro: //Si se obtiene carro negro, aparecerá un carro con las siguientes validaciones:
                    {
                        bool semovio = false;
                        // el carro busca subir para alcanzar al jugador
                        ///como el personaje esta arriba significa que no hay validar los limites de Y
                        if (carro.posy > personajey)
                        {
                            siguiente = matrizposiciones[carro.posy - 1, carro.posx];
                            if (siguiente == calle)
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                //carro subio en Y
                                carro.posy--;
                                matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                semovio = true;
                                //se mueve para arriba ahora probara moverse para la derecha
                                Movercarroderechacarronegro(carro);
                            }
                            else if ((valorencima == calle) && ((siguiente == principal) || (siguiente == principalconanciano) || (siguiente == principalconmascota)))
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                carro.posy--;
                                matrizposiciones[carro.posy, carro.posx] = atropellado;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[atropellado];
                                if ((tieneanciano == true) || (tienemascota == true))
                                {
                                    puntaje += carro.choque(true);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                                else
                                {
                                    puntaje += carro.choque(false);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                                semovio = true;
                            }
                            else
                                semovio = false;
                        }
                        //busca bajar para alcanzar al jugador
                        else if (carro.posy < personajey)
                        {
                            siguiente = matrizposiciones[carro.posy + 1, carro.posx];
                            if (siguiente == calle)
                            {

                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                carro.posy++;
                                matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                //se mueve para abajo
                                semovio = true;
                                Movercarroderechacarronegro(carro);

                            }
                            else if ((valorencima == calle) && ((siguiente == principal) || (siguiente == principalconanciano) || (siguiente == principalconmascota)))
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                carro.posy++;
                                matrizposiciones[carro.posy, carro.posx] = atropellado;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[atropellado];
                                semovio = true;
                                if ((tieneanciano == true) || (tienemascota == true))
                                {
                                    puntaje += carro.choque(true);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                                else
                                {
                                    puntaje += carro.choque(false);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                            }
                            else
                            {
                                semovio = false;
                            }
                        }
                        //le queda tratar mover a la derecha
                        if (semovio == false)
                        {
                            semovio = Movercarroderechacarronegro(carro);
                        }
                        if (semovio == false)
                        {

                            siguiente = matrizposiciones[carro.posy - 1, carro.posx];
                            if (siguiente == calle)
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                //carro subio en Y
                                carro.posy--;
                                matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                semovio = true;
                                Movercarroderechacarronegro(carro);
                            }
                            else
                            {
                                siguiente = matrizposiciones[carro.posy + 1, carro.posx];
                                if (siguiente == calle)
                                {
                                    matrizposiciones[carro.posy, carro.posx] = calle;
                                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                    //carro bajo en Y
                                    carro.posy++;
                                    matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                    semovio = true;
                                    Movercarroderechacarronegro(carro);
                                }
                            }
                        }

                    }
                    break;
                case carrorojo: //Si se obtiene carro rojo, aparecerá un carro con las siguientes validaciones:
                    {
                        bool semovio = false;
                        // el carro busca subir para alcanzar al jugador
                        ///como el personaje esta arriba significa que no hay validar los limites de Y
                        if (carro.posy > personajey)
                        {
                            siguiente = matrizposiciones[carro.posy - 1, carro.posx];
                            if (siguiente == calle)
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                //carro subio en Y
                                carro.posy--;
                                matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                semovio = true;
                                //se mueve para arriba ahora probara moverse para la derecha
                                semovio = Movimientocarrorojo(carro);
                            }
                            else if ((valorencima == calle) && ((siguiente == principal) || (siguiente == principalconanciano) || (siguiente == principalconmascota)))
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                carro.posy--;
                                matrizposiciones[carro.posy, carro.posx] = atropellado;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[atropellado];
                                if ((tieneanciano == true) || (tienemascota == true))
                                {
                                    puntaje += carro.choque(true);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                                else
                                {
                                    puntaje += carro.choque(false);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                                semovio = true;
                            }
                            else
                                semovio = false;
                        }
                        //busca bajar para alcanzar al jugador
                        else if (carro.posy < personajey)
                        {
                            siguiente = matrizposiciones[carro.posy + 1, carro.posx];
                            if (siguiente == calle)
                            {

                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                carro.posy++;
                                matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                //se mueve para abajo
                                semovio = true;
                                Movimientocarrorojo(carro);

                            }
                            else if ((valorencima == calle) && ((siguiente == principal) || (siguiente == principalconanciano) || (siguiente == principalconmascota)))
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                carro.posy++;
                                matrizposiciones[carro.posy, carro.posx] = atropellado;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[atropellado];
                                semovio = true;
                                if ((tieneanciano == true) || (tienemascota == true))
                                {
                                    puntaje += carro.choque(true);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                                else
                                {
                                    puntaje += carro.choque(false);
                                    label1.Text = "Puntaje: " + puntaje.ToString();
                                }
                            }
                            else
                            {
                                semovio = false;
                            }
                        }
                        //le queda tratar mover a la derecha

                        if (semovio == false)
                        {
                            semovio = Movimientocarrorojo(carro);
                        }
                        if (semovio == false)
                        {

                            siguiente = matrizposiciones[carro.posy - 1, carro.posx];
                            if (siguiente == calle)
                            {
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                //carro subio en Y
                                carro.posy--;
                                matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                semovio = true;
                                semovio = Movimientocarrorojo(carro);
                            }
                            else
                            {
                                siguiente = matrizposiciones[carro.posy + 1, carro.posx];
                                if (siguiente == calle)
                                {
                                    matrizposiciones[carro.posy, carro.posx] = calle;
                                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                                    //carro bajo en Y
                                    carro.posy++;
                                    matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                                    semovio = true;
                                    semovio = Movimientocarrorojo(carro);
                                }
                            }
                        }

                    }
                    break;
                    break;
                case carroamarillo: //Si se obtiene carro azul, aparecerá un carro con las siguientes validaciones:
                    {
                        if (carro.posx < limitex)
                        {
                            if (carro.posx != 29)
                            {
                                siguiente = matrizposiciones[carro.posy, carro.posx + 1];
                            }
                            if (siguiente == principal)
                            {
                                //se restan los puntos (la funcion regresa negativos)
                                puntaje += carro.choque(false);
                                label1.Text = "Puntaje: " + puntaje.ToString();
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[atropellado];
                                matrizposiciones[personajey, personajex] = atropellado;
                                if (carro.posx < limitex - 2)
                                {
                                    siguiente = matrizposiciones[carro.posy, carro.posx + 2];
                                    if (siguiente == calle)
                                    {
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                        matrizposiciones[carro.posy, carro.posx] = calle;
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[carro.tipocarro];
                                        matrizposiciones[carro.posy, carro.posx + 2] = carro.tipocarro;
                                    }
                                    else if (siguiente == semaforoverde)
                                    {

                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                        matrizposiciones[carro.posy, carro.posx] = calle;
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 1].Value = imageList2.Images[semaforoverde];
                                        matrizposiciones[carro.posy, carro.posx + 1] = semaforoverde;
                                    }


                                }

                            }
                            else if (carro.posx == 28)
                            {
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                            }
                            else if (siguiente == calle)
                            {

                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 1].Value = imageList2.Images[carro.tipocarro];
                                matrizposiciones[carro.posy, carro.posx + 1] = carro.tipocarro;
                            }
                        }
                    }
                    break;
                case carroverde: //Si se obtiene carro azul, aparecerá un carro con las siguientes validaciones:
                    {
                        if (carro.posx < limitex)
                        {
                            if (carro.posx != 29)
                            {
                                siguiente = matrizposiciones[carro.posy, carro.posx + 1];
                            }
                            if (siguiente == principal)
                            {
                                //se restan los puntos (la funcion regresa negativos)
                                puntaje += carro.choque(false);
                                label1.Text = "Puntaje: " + puntaje.ToString();
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[atropellado];
                                matrizposiciones[personajey, personajex] = atropellado;
                                if (carro.posx < limitex - 2)
                                {
                                    siguiente = matrizposiciones[carro.posy, carro.posx + 2];
                                    if (siguiente == calle)
                                    {
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                        matrizposiciones[carro.posy, carro.posx] = calle;
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[carro.tipocarro];
                                        matrizposiciones[carro.posy, carro.posx + 2] = carro.tipocarro;
                                    }
                                    else if (siguiente == semaforoverde)
                                    {

                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                        matrizposiciones[carro.posy, carro.posx] = calle;
                                        Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[semaforoverde];
                                        matrizposiciones[carro.posy, carro.posx + 2] = semaforoverde;
                                    }


                                }

                            }
                            else if (carro.posx == 28)
                            {
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                            }
                            else if (siguiente == calle)
                            {

                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                                matrizposiciones[carro.posy, carro.posx] = calle;
                                Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 1].Value = imageList2.Images[carro.tipocarro];
                                matrizposiciones[carro.posy, carro.posx + 1] = carro.tipocarro;
                            }
                        }
                    }
                    break;


            }
        }
        private bool Movercarroderechacarronegro(Carro carro)
        {
            int siguiente = 0;
            bool semovio = false;
            if (carro.posx < limitex)
            {
                if (carro.posx != 29)
                {
                    siguiente = matrizposiciones[carro.posy, carro.posx + 1];
                }
                if (carro.posx == 28)
                {
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                    matrizposiciones[carro.posy, carro.posx] = calle;
                }
                else if (siguiente == calle)
                {
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                    carro.posx++;
                    matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                    semovio = true;
                }
                else if (siguiente == semaforoverde)
                {
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[carro.tipocarro];
                    matrizposiciones[carro.posy, carro.posx + 2] = carro.tipocarro;
                    semovio = true;
                }
                else if (siguiente == semafororojo)
                {
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[carro.tipocarro];
                    matrizposiciones[carro.posy, carro.posx + 2] = carro.tipocarro;
                    semovio = true;
                }
                else if (((siguiente == principal) || (siguiente == principalconanciano) || (siguiente == principalconmascota)))
                {
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                    carro.posx++;
                    matrizposiciones[carro.posy, carro.posx] = atropellado;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[atropellado];
                    semovio = true;
                    if ((tieneanciano == true) || (tienemascota == true))
                    {
                        puntaje += carro.choque(true);
                        label1.Text = "Puntaje: " + puntaje.ToString();
                    }
                    else
                    {
                        puntaje += carro.choque(false);
                        label1.Text = "Puntaje: " + puntaje.ToString();
                    }
                }
            }
            return semovio;
        }
        private bool Movimientocarrorojo(Carro carro)
        {
            int siguiente = 0;
            bool semovio = false;
            if (carro.posx < limitex)
            {

                siguiente = matrizposiciones[carro.posy, carro.posx + 1];
                if (carro.posx == 28 && siguiente == calle)
                {
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                    matrizposiciones[carro.posy, carro.posx] = calle;
                }
                else if (siguiente == semafororojo)
                {
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[carro.tipocarro];
                    matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                    semovio = true;
                }
                else if (siguiente == semaforoverde)
                {
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx].Value = imageList2.Images[calle];
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero.Rows[carro.posy].Cells[carro.posx + 2].Value = imageList2.Images[carro.tipocarro];
                    matrizposiciones[carro.posy, carro.posx + 2] = carro.tipocarro;
                    semovio = true;
                }
                else if (siguiente == calle)
                {
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                    carro.posx++;
                    matrizposiciones[carro.posy, carro.posx] = carro.tipocarro;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[carro.tipocarro];
                    semovio = true;
                }
                else if (((siguiente == principal) || (siguiente == principalconanciano) || (siguiente == principalconmascota)))
                {
                    matrizposiciones[carro.posy, carro.posx] = calle;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[calle];
                    carro.posx++;
                    matrizposiciones[carro.posy, carro.posx] = atropellado;
                    Dgv_tablero[carro.posx, carro.posy].Value = imageList2.Images[atropellado];
                    semovio = true;
                    if ((tieneanciano == true) || (tienemascota == true))
                    {
                        puntaje += carro.choque(true);
                        label1.Text = "Puntaje: " + puntaje.ToString();
                    }
                    else
                    {
                        puntaje += carro.choque(false);
                        label1.Text = "Puntaje: " + puntaje.ToString();
                    }
                }
            }
            return semovio;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Random rand = new Random();
            int next = rand.Next(0, 10);

            int filacarro = callesnivel2[next];
            next = rand.Next(0, 5);

            int valorcarro = tipocarro[next];
            matrizposiciones[filacarro, 0] = valorcarro;

            Dgv_tablero[0, filacarro].Value = imageList2.Images[valorcarro];
            Carro carro = new Carro();
            for (int i = 29; i >= 0; i--)
            {
                for (int j = 29; j >= 0; j--)
                {
                    if ((matrizposiciones[i, j] == carroamarillo) || (matrizposiciones[i, j] == carroazul) || (matrizposiciones[i, j] == carronegro) || (matrizposiciones[i, j] == carrorojo) || (matrizposiciones[i, j] == carroverde))
                    {
                        carro.posx = j;
                        carro.posy = i;
                        carro.tipocarro = matrizposiciones[i, j];
                        movercarro(carro);

                    }
                }
            }
        }
        private void timer2_Tick(object sender, EventArgs e)
        {

        }
        private void timer3_Tick(object sender, EventArgs e)
        {

          
        }

        bool tieneanciano = false;
        bool tienemascota = false;
        int caminaancianoderecha = 0;
        int caminamascotaderecha = 0;
        int caminaancianoizquierda = 0;
        int caminamascotaizquierda = 0;
        int caminaancianoarriba = 0;
        int caminamascotaarriba = 0;
        int caminaancianoabajo = 0;
        int caminamascotaabajo = 0;
        int valorencima = grama;
        private int limitey = 20;
        private int inicioy = 1;

        private void nivel_2_KeyUp(object sender, KeyEventArgs e)
        {
            if (timer1.Enabled == true) //Validación para que solo funcione mientras el timer esté funcionando
            {
                if (e.KeyCode == Keys.D)
                {
                    if (((tieneanciano == true) && (caminaancianoderecha == 2)) || ((tienemascota == true) && (caminamascotaderecha == 1)) || ((tienemascota == false) && (tieneanciano == false)))
                    //Validacion para que cuado tenga anciano tenga que presionarse la flecha derecha 3 veces, cuando tenga mascota 2, y cuando esté solo, solo 1
                    {
                        //limite -1 ya que el cero cuenta
                        if (personajex < (limitex - 1))//Validación para que el personaje principal no salga del límite
                        {
                            //En la posición en la que estaba el personaje se imprime y se guarda en la matríz lo que había antes, que queda guardado en valorencima
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[valorencima];
                            matrizposiciones[personajey, personajex] = valorencima;

                            //La posición en x del personaje aumenta en 1 y valor encima guarda "que había" en la nueva posición
                            personajex++;
                            valorencima = matrizposiciones[personajey, personajex];

                            if (tienemascota == true)
                            {
                                //Si se cumple el movimiento y tiene mascota la imagen de personaje que se imprime es en la que el personaje tiene un perro
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconmascota;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];
                            }
                            else if (tieneanciano == true)
                            {
                                //Si se cumple el movimiento y tiene anciano la imagen de personaje que se imprime es en la que lo acompaña un anciano
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconanciano;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];
                            }
                            else
                            {
                                //Se imprime el personaje en la nueva posición x, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principal;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal];
                            }
                        }
                    }
                    else //Si no se han presionado las 2 veces cuando tiene mascota o las tres veces cuando tiene anciano:
                    {
                        if (tieneanciano) //Si tiene anciano el contador caminaancianoderecha aumenta en 1 hasta llegar a 2 ( puede tomar estos valores: 0, 1, 2)
                        {
                            caminaancianoderecha++;
                            //Se incluyen todos los contadores para que se presione la flecha derecha 3 veces SEGUIDAS
                        }
                        else if (tienemascota) //Si tiene anciano el contador caminamascotaderecha aumenta en 1 hasta llegar a 1 ( puede tomar estos valores: 0, 1)
                        {
                            caminamascotaderecha++;
                            //Se incluyen todos los contadores para que se presione la flecha derecha 2 veces SEGUIDAS
                        }
                    }

                }
                else if (e.KeyCode == Keys.A)

                {
                    if (((tieneanciano == true) && (caminaancianoizquierda == 2)) || ((tienemascota == true) && (caminamascotaizquierda == 1)) || ((tienemascota == false) && (tieneanciano == false)))
                    //Validación para que cuado tenga anciano tenga que presionarse la flecha derecha 3 veces, cuando tenga mascota 2, y cuando esté solo, solo 1
                    {

                        //Validación para que el personaje no salga de los límetes de la matríz
                        if (personajex > 0)
                        {
                            //Se inician las variables en cero cada vez que se cumple el movimiento
                            caminaancianoderecha = 0;
                            caminamascotaderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;

                            //En la posición en la que estaba el personaje se imprime y se guarda en la matríz lo que había antes, que queda guardado en valorencima
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[valorencima];
                            matrizposiciones[personajey, personajex] = valorencima;

                            //La posición en x del personaje disminuye en 1 y valor encima guarda "que había" en la nueva posición
                            personajex--;
                            valorencima = matrizposiciones[personajey, personajex];

                            if (tienemascota == true)
                            {
                                //Si se cumple el movimiento y tiene mascota la imagen de personaje que se imprime es en la que el personaje tiene un perro
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconmascota;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];
                            }
                            else if (tieneanciano == true)
                            {
                                //Si se cumple el movimiento y tiene anciano la imagen de personaje que se imprime es en la que lo acompaña un anciano
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconanciano;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];
                            }
                            else
                            {
                                //Se imprime el personaje en la nueva posición x, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principal;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[0];
                            }
                        }
                    }
                    else
                    {
                        if (tieneanciano)//Si tiene anciano el contador caminaancianoizquierda aumenta en 1 hasta llegar a 2 (puede tomar estos valores: 0, 1, 2)
                        {
                            caminaancianoderecha = 0;
                            caminamascotaderecha = 0;
                            caminaancianoizquierda++;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;
                            //Se incluyen todos los contadores para que se presione la flecha izquierda 3 veces SEGUIDAS
                        }
                        else if (tienemascota)//Si tiene anciano el contador caminamascotaizquierda aumenta en 1 hasta llegar a 1 (puede tomar estos valores: 0, 1)
                        {
                            caminamascotaderecha = 0;
                            caminaancianoderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda++;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;
                            //Se incluyen todos los contadores para que se presione la flecha izquierda 2 veces SEGUIDAS
                        }
                    }

                }
                else if (e.KeyCode == Keys.S)
                {
                    if (((tieneanciano == true) && (caminaancianoabajo == 2)) || ((tienemascota == true) && (caminamascotaabajo == 1)) || ((tienemascota == false) && (tieneanciano == false)))
                    //Validación para que cuado tenga anciano tenga que presionarse la flecha derecha 3 veces, cuando tenga mascota 2, y cuando esté solo, solo 1
                    {
                        //limite -1 ya que el cero cuenta
                        if (personajey < limitey - 1)
                        {
                            //Se inician las variables en cero cada vez que se cumple el movimiento
                            caminaancianoderecha = 0;
                            caminamascotaderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;

                            //En la posición en la que estaba el personaje se imprime y se guarda en la matríz lo que había antes, que queda guardado en valorencima
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[valorencima];
                            matrizposiciones[personajey, personajex] = valorencima;

                            //La posición en y del personaje aumenta en 1 y valor encima guarda "que había" en la nueva posición
                            personajey++;
                            valorencima = matrizposiciones[personajey, personajex];

                            if (tienemascota == true)
                            {
                                //Si se cumple el movimiento y tiene mascota la imagen de personaje que se imprime es en la que el personaje tiene un perro
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconmascota;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];
                            }
                            else if (tieneanciano == true)
                            {
                                //Si se cumple el movimiento y tiene anciano la imagen de personaje que se imprime es en la que lo acompaña un anciano
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconanciano;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];
                            }
                            else
                            {
                                //Se imprime el personaje en la nueva posición x, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principal;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal];
                            }
                        }
                    }
                    else
                    {
                        if (tieneanciano)//Si tiene anciano el contador caminaancianoizquierda aumenta en 1 hasta llegar a 2 (puede tomar estos valores: 0, 1, 2)
                        {
                            caminaancianoderecha = 0;
                            caminamascotaderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo++;
                            caminamascotaabajo = 0;
                            //Se incluyen todos los contadores para que se presione la flecha abajo 3 veces SEGUIDAS
                        }
                        else if (tienemascota)//Si tiene anciano el contador caminamascotaizquierda aumenta en 1 hasta llegar a 1 (puede tomar estos valores: 0, 1)
                        {
                            caminamascotaderecha = 0;
                            caminaancianoderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo++;
                            //Se incluyen todos los contadores para que se presione la flecha abajo 3 veces SEGUIDAS
                        }
                    }

                }
                else if (e.KeyCode == Keys.W)
                {
                    if (((tieneanciano == true) && (caminaancianoarriba == 2)) || ((tienemascota == true) && (caminamascotaarriba == 1)) || ((tienemascota == false) && (tieneanciano == false)))
                    //Validación para que cuado tenga anciano tenga que presionarse la flecha derecha 3 veces, cuando tenga mascota 2, y cuando esté solo, solo 1
                    {

                        //Validación para que el personaje no salga de los límetes de la matriz
                        if (personajey > inicioy)
                        {//Se inician las variables en cero cada vez que se cumple el movimiento
                            caminaancianoderecha = 0;
                            caminamascotaderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;

                            //En la posición en la que estaba el personaje se imprime y se guarda en la matríz lo que había antes, que queda guardado en valorencima
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[valorencima];
                            matrizposiciones[personajey, personajex] = valorencima;

                            //La posición en y del personaje disminuye en 1 y valor encima guarda "que había" en la nueva posición
                            personajey--;
                            valorencima = matrizposiciones[personajey, personajex];

                            if (tienemascota == true)
                            {
                                //Si se cumple el movimiento y tiene mascota la imagen de personaje que se imprime es en la que el personaje tiene un perro
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconmascota;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];
                            }
                            else if (tieneanciano == true)
                            {
                                //Si se cumple el movimiento y tiene anciano la imagen de personaje que se imprime es en la que lo acompaña un anciano
                                //Se imprime en la nueva posición x del personaje, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principalconanciano;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];
                            }
                            else
                            {
                                //Se imprime el personaje en la nueva posición x, se muestra en el datagrid y se guarda en la matriz
                                matrizposiciones[personajey, personajex] = principal;
                                Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal];
                            }
                        }
                    }
                    else
                    {
                        if (tieneanciano)//Si tiene anciano el contador caminaancianoarriba aumenta en 1 hasta llegar a 2 (puede tomar estos valores: 0, 1, 2)
                        {
                            caminaancianoderecha = 0;
                            caminamascotaderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba++;
                            caminamascotaarriba = 0;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;
                            //Se incluyen todos los contadores para que se presione la flecha arriba 3 veces SEGUIDAS
                        }
                        else if (tienemascota)//Si tiene anciano el contador caminamascotaarriba aumenta en 1 hasta llegar a 1 (puede tomar estos valores: 0, 1)
                        {
                            caminamascotaderecha = 0;
                            caminaancianoderecha = 0;
                            caminaancianoizquierda = 0;
                            caminamascotaizquierda = 0;
                            caminaancianoarriba = 0;
                            caminamascotaarriba++;
                            caminaancianoabajo = 0;
                            caminamascotaabajo = 0;
                            //Se incluyen todos los contadores para que se presione la flecha izquierda 2 veces SEGUIDAS
                        }
                    }

                }
                else if (e.KeyCode == Keys.Q)
                {
                    //orden para validar si tiene una mascota o anciano a un lado: izquierda, derecha, arriba, abajo

                    //IZQUIERDA
                    if ((personajex > 0) && (tienemascota == false) && (tieneanciano == false))//valida que no tenga una mascota o anciano antes
                    {
                        if (matrizposiciones[personajey, personajex - 1] == mascota)//Si a la izquierda del personaje se encuentra una mascota la toma
                        {
                            tienemascota = true; //Se vuelve true la variable tiene mascota, que afecta la cantidad de veces que debe presionar las flechas
                            matrizposiciones[personajey, personajex - 1] = calle; //Se guarda calle en la posición izquierda del personaje, donde estaba la mascota (En la matriz) 
                            Dgv_tablero.Rows[personajey].Cells[personajex - 1].Value = imageList2.Images[calle]; //Se imprime calle en la posicion a la izquierda del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconmascota;//En la posicion del personaje se guarda en la matriz 14, que es el número de la imagen del personaje con mascota
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];//Se muestra en el datagrid, la imagen del principal con mascota en la posición del jugador

                        }
                        else if (matrizposiciones[personajey, personajex - 1] == anciano)
                        {
                            tieneanciano = true; //Se vuelve true la variable tiene mascota, que afecta la cantidad de veces que debe presionar las flechas
                            matrizposiciones[personajey, personajex - 1] = calle; //Se guarda calle en la posición izquierda del personaje,  donde estaba el anciano (En la matriz) 
                            Dgv_tablero.Rows[personajey].Cells[personajex - 1].Value = imageList2.Images[calle]; //Se imprime calle en la posicion a la izquierda del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconanciano; //En la posicion del personaje se guarda en la matriz 15, que es el número de la imagen del personaje con anciano
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano]; //Se muestra en el datagrid, la imagen del principal con anciano en la posición del jugador

                        }
                    }
                    //DERECHA
                    if (personajex < limitex - 1 && (tienemascota == false) && (tieneanciano == false))//valida que no tenga una mascota o anciano antes
                    {
                        if (matrizposiciones[personajey, personajex + 1] == mascota)//Si no hay nada a la izquierda, pero a la derecha del personaje se encuentra una mascota la toma
                        {
                            tienemascota = true; //Se vuelve true la variable tiene mascota
                            matrizposiciones[personajey, personajex + 1] = calle; //Se guarda calle en la posición a la derecha del personaje,  donde estaba la mascota (En la matriz) 
                            Dgv_tablero.Rows[personajey].Cells[personajex + 1].Value = imageList2.Images[calle]; //Se imprime calle en la posicion a la derechca del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconmascota;//En la posicion del personaje se guarda en la matriz 14, que es el número de la imagen del personaje con mascota
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];//Se muestra en el datagrid, la imagen del principal con mascota en la posición del jugador

                        }
                        else if (matrizposiciones[personajey, personajex + 1] == anciano)//Si no hay nada a la izquierda, pero a la derecha del personaje se encuentra un anciano, lo toma
                        {
                            tieneanciano = true;
                            matrizposiciones[personajey, personajex + 1] = calle; //Se guarda calle en la posición a la derecha del personaje,  donde estaba el anciano (En la matriz) 
                            Dgv_tablero.Rows[personajey].Cells[personajex + 1].Value = imageList2.Images[calle]; //Se imprime calle en la posicion a la derechca del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconanciano;//En la posicion del personaje se guarda en la matriz 15, que es el número de la imagen del personaje con anciano
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];//Se muestra en el datagrid, la imagen del principal con anciano en la posición del jugador

                        }
                    }
                    //ARRIBA
                    if ((personajey > 0) && (tienemascota == false) && (tieneanciano == false))//valida que no tenga una mascota o anciano antes
                    {
                        if (matrizposiciones[personajey - 1, personajex] == mascota)//Si no hay nada a la izquierda, ni derechca, pero arriba del personaje se encuentra una mascota, la toma
                        {
                            tienemascota = true;
                            matrizposiciones[personajey - 1, personajex] = calle;//Se guarda calle en la posición arriba del personaje,  donde estaba la mascota (En la matriz)
                            Dgv_tablero.Rows[personajey - 1].Cells[personajex].Value = imageList2.Images[calle];//Se imprime calle en la posicion arriba del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconmascota;//En la posicion del personaje se guarda en la matriz 14, que es el número de la imagen del personaje con mascota
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];//Se muestra en el datagrid, la imagen del principal con mascota en la posición del jugador

                        }
                        else if (matrizposiciones[personajey - 1, personajex] == anciano)//Si no hay nada a la izquierda, ni derechca, pero arriba del personaje se encuentra un anciano, lo toma
                        {
                            tieneanciano = true;
                            matrizposiciones[personajey - 1, personajex] = calle;//Se guarda calle en la posición arriba del personaje,  donde estaba el anciano (En la matriz)
                            Dgv_tablero.Rows[personajey - 1].Cells[personajex].Value = imageList2.Images[calle];//Se imprime calle en la posicion arriba del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconanciano;//En la posicion del personaje se guarda en la matriz 15, que es el número de la imagen del personaje con anciano
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];//Se muestra en el datagrid, la imagen del principal con anciano en la posición del jugador

                        }
                    }
                    //ABAJO
                    if (personajey < limitey - 1 && (tienemascota == false) && (tieneanciano == false))//valida que no tenga una mascota o anciano antes
                    {
                        if (matrizposiciones[personajey + 1, personajex] == mascota)//Si no hay nada a la izquierda, ni derechca, ni arriba, pero abajo del personaje se encuentra una mascota, la toma
                        {
                            tienemascota = true;
                            matrizposiciones[personajey + 1, personajex] = calle;//Se guarda calle en la posición abajo del personaje,  donde estaba la mascota (En la matriz)
                            Dgv_tablero.Rows[personajey + 1].Cells[personajex].Value = imageList2.Images[calle]; //Se imprime calle en la posicion abajo del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconmascota; //En la posicion del personaje se guarda en la matriz 14, que es el número de la imagen del personaje con mascota
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconmascota];//Se muestra en el datagrid, la imagen del principal con mascota en la posición del jugador

                        }
                        else if (matrizposiciones[personajey + 1, personajex] == anciano)//Si no hay nada a la izquierda, ni derechca, ni arriba, pero abajo del personaje se encuentra una mascota, la toma
                        {
                            tieneanciano = true;
                            matrizposiciones[personajey + 1, personajex] = calle;//Se guarda calle en la posición abajo del personaje,  donde estaba el anciano (En la matriz)
                            Dgv_tablero.Rows[personajey + 1].Cells[personajex].Value = imageList2.Images[calle];//Se imprime calle en la posicion abajo del personaje en el datagrid
                            matrizposiciones[personajey, personajex] = principalconanciano;//En la posicion del personaje se guarda en la matriz 15, que es el número de la imagen del personaje con anciano
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principalconanciano];//Se muestra en el datagrid, la imagen del principal con anciano en la posición del jugador

                        }
                    }

                }
                else if (e.KeyCode == Keys.E)
                {
                    if (valorencima == calle) //Si en valorencima quedó guardado 6 (calle)
                    {
                        if (tieneanciano == true)//Valida que esté transportando un anciano
                        {
                            valorencima = anciano; //El anciano se puede soltar en la calle
                            tieneanciano = false;
                            matrizposiciones[personajey, personajex] = principal; //La imagen del personaje vuelve a ser la primcipal (en la matriz)
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal]; //La imagen que se muestra en el datagrid vuelve a ser la principal
                        }
                        else if (tienemascota == true)//Valida que esté transportando una mascota
                        {
                            valorencima = mascota; //El anciano se puede soltar en la calle
                            tienemascota = false;
                            matrizposiciones[personajey, personajex] = principal; //La imagen del personaje vuelve a ser la primcipal (en la matriz)
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal]; //La imagen que se muestra en el datagrid vuelve a ser la principal
                        }
                    }
                    else if (valorencima == grama) //Si en valorencima quedó guardado 7 (calle)
                    {
                        puntaje += 10;
                        label1.Text = "Puntaje: " + puntaje.ToString();
                        matrizposiciones[personajey, personajex] = principal;
                        Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal];
                        if (tieneanciano == true)//Valida que esté transportando un anciano
                        {
                            valorencima = anciano; //El anciano se puede soltar en la calle
                            tieneanciano = false;
                            matrizposiciones[personajey, personajex] = principal; //La imagen del personaje vuelve a ser la primcipal (en la matriz)
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal]; //La imagen que se muestra en el datagrid vuelve a ser la principal
                        }
                        else if (tienemascota == true)//Valida que esté transportando una mascota
                        {
                            valorencima = mascota; //El anciano se puede soltar en la calle
                            tienemascota = false;
                            matrizposiciones[personajey, personajex] = principal; //La imagen del personaje vuelve a ser la primcipal (en la matriz)
                            Dgv_tablero.Rows[personajey].Cells[personajex].Value = imageList2.Images[principal]; //La imagen que se muestra en el datagrid vuelve a ser la principal
                        }

                    }
                }
            }

        }
        private void nivel_2_KeyDown(object sender, KeyEventArgs e)
        {

        }

        private void Dgv_tablero_Move(object sender, EventArgs e)
        {

        }

        private void Dgv_tablero_KeyUp(object sender, KeyEventArgs e)
        {

        }
    }
}
