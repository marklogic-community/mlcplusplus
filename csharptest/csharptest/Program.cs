using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using mlclient;

namespace csharptest
{
    class Program
    {
        static void Main(string[] args)
        {
            mlclient.Connection conn = new mlclient.Connection();
            Console.Out.WriteLine("Please enter your MarkLogic Server Hostname or IP Address, and hit enter.");
            string hostname = Console.In.ReadLine();
            Console.Out.WriteLine("Please enter your MarkLogic Server REST API Port Number, and hit enter.");
            string port = Console.In.ReadLine();
            Console.Out.WriteLine("Please enter your MarkLogic Server Username, and hit enter.");
            string user = Console.In.ReadLine();
            Console.Out.WriteLine("Please enter your MarkLogic Server Password, and hit enter.");
            string pass = Console.In.ReadLine();
            Console.Out.WriteLine("Please enter the URI of the document you wish to view, and hit enter.");
            string uri = Console.In.ReadLine();

            conn.configure(hostname, port, user, pass);
            Document doc = new Document();
            doc.setUri(uri);
            Response resp = conn.getDocumentContent(doc);
            // TODO handle errors
            Console.Out.WriteLine("The content of your document is as follows:-");
            Console.Out.WriteLine(resp.getContent());

            Console.Out.WriteLine("Done! Hit any key to exit.");
            char[] buffer = new char['c'];
            int outcome = Console.In.ReadBlock(buffer, 0, 1);
        }
    }
}