using System;

using mlclient;

namespace cssearch
{
	class MainClass
	{
		public static void Main(string[] args)
		{

			Console.WriteLine("Running search...");
			if (args.Length < 1)
			{
				Console.WriteLine("Must specify a search string text as first parameter" );
				Console.WriteLine("Usage: cssearch.exe <querytext>" );
				Console.WriteLine("Example Usage: cssearch.exe wibble" );
				return;
			}

			Connection conn = new mlclient.Connection();
			conn.configure("192.168.123.4", "8122", "admin", "admin", false);

			SearchDescription desc = new SearchDescription();
			desc.setQueryText(args[0]);
			Response response = conn.search(desc);

			Console.WriteLine("  Response Type: ");
			Console.WriteLine("  Response Code: ");
			Console.WriteLine("  Response Content: ");

			Console.WriteLine("Search Results:-");
			Console.WriteLine(response.getContent());

			Console.WriteLine("search complete");
			return;
		}
	}
}
