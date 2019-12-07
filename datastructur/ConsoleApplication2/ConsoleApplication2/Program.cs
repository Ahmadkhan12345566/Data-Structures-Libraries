using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            circle c = new circle();

        }
    }

    class circle
    {
        // member
        private int radius;

        // set get
        public int Radius
        {
            get { return this.radius; }
            set { radius = value; }
        }

        public circle() { this.radius = 0; }
        public circle(int c) { this.radius = c; }
    }

    class cylinder : circle
    {
        // member
        private int length;
        // set get
        public int Length
        {
            get { return this.length; }
            set { length = value; }
        }

        public cylinder() : base()
        { this.length = 0; }

        public cylinder(int length) : base()
        { this.length =length; }

    }
}
