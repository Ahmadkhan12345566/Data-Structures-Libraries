using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            BOOk b = new BOOk();
            b.Name = "";
        }
    }
}



class BOOk {
    string name;
    static int a;


    

    public BOOk()
    {
        this.name = "";
    }

    BOOk(string Name) {

        this.name = Name;
    }

    public string Name
    {
        get
        {
            return name;
        }

        set
        {
            name = value;
        }
    }


    public static void Asif() {
        a = 3;


    }
}