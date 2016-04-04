using System;

namespace ReactGraph.Kernel
{
    public interface IEdge : INode
    {
        INode Source { get; }

        INode Destination { get; }
    }
}