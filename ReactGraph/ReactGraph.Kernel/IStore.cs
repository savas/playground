using System;
using System.Threading.Tasks;

namespace ReactGraph.Kernel
{
    public interface IStore<T> where T : IStoreEntity
    {
        Task New (T entity);

        Task<T> Get (Uri id);

        Task Update (T entity);

        Task Delete (Uri id);
    }
}

