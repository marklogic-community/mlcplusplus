using System;

using mlclient;

namespace csbatchupload
{
	class UploadObserver : IBatchNotifiable
	{
		public void batchOperationComplete(SWIGTYPE_p_std__vectorT_std__string_t out_uris, bool success, 
		                                   SWIGTYPE_p_std__exception problem)
		{
			Console.WriteLine(out_uris.ToString);
			// TODO make the above STL containers usable
		}
	}
	class MainClass
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Running csbatchupload...");

			if (args.Length < 3)
			{
				Console.WriteLine("Must specify the root load folder as first parameter");
				Console.WriteLine("Must specify the collection as second parameter");
				Console.WriteLine("Usage: " + args[0] + " <folder> <collection>");
				Console.WriteLine("Example Usage: " + args[0] + " ./some/folder mydocs");
				return;
			}

			UploadObserver obs = new UploadObserver();

			Connection conn = new mlclient.Connection();
			conn.configure("192.168.123.4", "8122", "admin", "admin", false);

			DocumentBatchWriter writer = new DocumentBatchWriter(conn);
			writer.addBatchListener(obs);
			System.Collections.ArrayList colList = new System.Collections.ArrayList();
			colList.Add(args[2]);
			System.Collections.ArrayList permList = new System.Collections.ArrayList();
			Permission perm = new Permission("Admin",Capability.EXECUTE);
			permList.Add(perm);

			DocumentSet set = new DocumentSet();
			DocumentBatchHelper.addFilesToDocumentSet(args[1], args[1], true, "/csbatchupload/",
													  colList, permList, null, set);
			long setSize = set.size();
			Console.WriteLine("Document Set Size: " + setSize);

			writer.assignDocuments(set);
			writer.send();

			writer.wait();


			//Console.WriteLine("Exception is nullptr?: " + (null == obs.ex) ); // TODO extract exception once STL is supported

			Progress p = writer.getProgress();
			Console.WriteLine("Document set size: " + setSize + ", complete size: " + p.completed );
			Console.WriteLine("Progress: Complete: " + p.completed + ", total: " + p.total + ", pct: " + p.percentageComplete );
			Console.WriteLine("Progress: duration: " + p.duration + ", est remaining duration: " 
			                  + p.durationEstimateRemaining);

			Console.WriteLine("batch upload complete");

		}
	}
}
