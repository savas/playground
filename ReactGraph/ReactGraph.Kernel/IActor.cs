using System;
using System.Threading.Tasks;

namespace ReactGraph.Kernel
{
    /*
	 * The actor abstraction
	 */
    public interface IActor
    {
        /*
		 * Enqueues the given message for processing. Implementations of this method
		 * should observe strict queuing semantics. The processing of a message must
		 * be complete before the processing of another can start. The returned Task
		 * represents the computation for enqueuing the message. The inner task
		 * represents the computation for processing the message.
         */
        Task<Task> process (IMessage msg);
    }
}