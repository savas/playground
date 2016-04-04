using System;
using System.Threading.Tasks;

namespace ReactGraph.Kernel
{
    public interface IGraph: IStore<INode>, IStore<IEdge>
    {
    }
}

