using System;
using System.Linq;
using System.Reactive.Linq;

namespace ReactGraph.Kernel
{
    public interface INode : IStoreEntity
    {
        IQbservable<T> Stream<T> ();

        IQueryable<T> Query<T> ();
    }
}