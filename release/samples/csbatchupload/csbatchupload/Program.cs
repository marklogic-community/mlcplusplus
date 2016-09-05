using System;

using mlclient;
using System.Threading;

namespace csbatchupload
{
	public class UploadObserver : IBatchNotifiable
	{
		public UploadObserver()
		{
			;
		}
		public SWIGTYPE_p_std__exception ex;
		public override void batchOperationComplete(DocumentUriSet out_uris, bool success,
		                                   SWIGTYPE_p_std__exception problem)
		{
			DocumentUriSet.DocumentUriSetEnumerator docIter = out_uris.GetEnumerator();
			while (docIter.MoveNext())
			{
				Console.WriteLine("  " + docIter.Current); 
			}
			ex = problem;
		}
	}
	public class MainClass
	{
		public static void Main(string[] args)
		{
			Console.WriteLine("Running csbatchupload...");

			if (args.Length < 2)
			{
				Console.WriteLine("Must specify the root load folder as first parameter");
				Console.WriteLine("Must specify the collection as second parameter");
				Console.WriteLine("Usage: csbatchupload <folder> <collection>");
				Console.WriteLine("Example Usage: csbatchupload ./some/folder mydocs");
				return;
			}

			UploadObserver obs = new UploadObserver();

			Connection conn = new mlclient.Connection();
			conn.configure("192.168.123.4", "8122", "admin", "admin", false);

			DocumentBatchWriter writer = new DocumentBatchWriter(conn);
			writer.addBatchListener(obs);
			CollectionSet colList = new CollectionSet();
			colList.Add(args[1]);
			PermissionSet permList = new PermissionSet();
			Permission perm = new Permission("admin",Capability.EXECUTE);
			permList.Add(perm);

			DocumentSet set = new DocumentSet();
			DocumentBatchHelper.addFilesToDocumentSet(args[0], args[0], true, "/csbatchupload/",
													  colList, permList, null, set);
			long setSize = set.Count;
			Console.WriteLine("Document Set Size: " + setSize);

			writer.assignDocuments(set);
			writer.send();

			writer.wait();

			//Thread.Sleep(5000); // hack around multi-threading issues


			Console.WriteLine("Exception is nullptr?: " + (null == obs.ex) ); // TODO extract exception once STL is supported

			Progress p = writer.getProgress();
			Console.WriteLine("Document set size: " + setSize + ", complete size: " + p.completed );
			Console.WriteLine("Progress: Complete: " + p.completed + ", total: " + p.total + ", pct: " + p.percentageComplete );
			Console.WriteLine("Progress: duration: " + p.duration + ", est remaining duration: " 
			                  + p.durationEstimateRemaining);
			Console.WriteLine("Progress: Overall rate: " + p.rate);

			Console.WriteLine("batch upload complete");

		}
	}
}
