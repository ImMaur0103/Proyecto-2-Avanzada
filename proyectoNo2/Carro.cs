using System;
using System.Collections.Generic;
using System.Linq;
 using System.Text;
using System.Threading.Tasks;

namespace proyectoNo2
{
    public class Carro
    {
        public int posx;
        public int posy;
        public int tipocarro;


        public Carro()
        {

        }
        int a;
        public int choque(bool transporta)
        {
            int retornar = -1;
            if (transporta)
            {
                retornar -= 5;
            }
            return retornar;
        }


    }
}
