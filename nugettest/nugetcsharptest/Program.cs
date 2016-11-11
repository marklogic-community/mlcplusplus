using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using mlclient;

namespace nugetcsharptest
{
    class Program
    {
        static void Main(string[] args)
        {
            mlclient.Connection conn = new mlclient.Connection();
            conn.configure("192.168.123.4", "8122", "admin", "admin");
            Document doc = new Document();
            doc.setUri("/some/doc.json");
            Response resp = conn.getDocumentContent(doc);
            Console.Out.WriteLine(resp.getContent());
            Console.Out.WriteLine("Done!");
        }
    }
}