using System;

using mlclient;

namespace csgetdoc
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine ("Running csgetdoc...");

			mlclient.Connection conn = new mlclient.Connection();
			conn.configure("192.168.123.4", "8122", "admin", "admin", false);
			string uri = "/zoo/animals/tiger.json";
			Console.WriteLine("Fetching: " + uri);
			mlclient.Response resp = conn.getDocument(uri);
			mlclient.ResponseType rt = resp.getResponseType();
			Console.WriteLine("Response Type: " + rt.ToString());
			if (mlclient.ResponseType.JSON == rt)
			{
				Console.WriteLine("This is a JSON document");
			}
			if (mlclient.ResponseType.XML == rt)
			{
				Console.WriteLine("This is an XML document");
			}
			Console.WriteLine(resp.getContent());

		}
	}
}
