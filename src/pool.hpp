#ifndef POOL_HPP_INCLUDED
#define POOL_HPP_INCLUDED

#include <stddef.h>

template <class T>
class Pool
{
	private:
		T *pool;
		bool *available;
		size_t size;
		
		bool initialised;
		
	public:
		// Constructors and destructors!
		Pool(unsigned int newSize) : size(newSize)
		{
			initialised = false;
			
			try
			{
				pool = new T [size];
				available = new bool [size];
				
				for (unsigned int slot = 0; slot < size; ++slot)
					available[slot] = true;
			}
			catch ( ... )
			{
				pool = nullptr; available = nullptr;
				return;
			}
			
			initialised = true;
		}
		
		~Pool()
		{
			if (pool) delete [] pool;
			if (available) delete [] available;
		}
		
		// Returns the first empty slot found or -1 on error!
		int getEmpty()
		{
			if (initialised)
				for (int slot = 0; slot < size; ++slot)
					if (available)
						return slot;
			
			return -1;
		}
		
		// Allocates the first empty slot found! (or -1 on error as above!)
		int allocate()
		{
			if (!initialised)
				return -1;
			
			int slot = getEmpty();
			
			if (slot != -1)
				available[slot] = false;

			return slot;
		}
		
		// Tries to allocate specified slot, returns it back if successful, or -1 if not.
		int allocate(unsigned int slot)
		{
			if (initialised)
				if (slot < size)
					if (available[slot])
					{
						available[slot] = false;
						return slot;
					}
			
			return -1;
		}
		
		// DEALLOCATES
		void deallocate(unsigned int slot)
		{
			if (initialised)
				if (slot < size)
					available[slot] = true;
		}
		
		inline T* operator[](unsigned int slot)
		{
			if (slot < size)
				if (!available[slot])
					return pool + slot;
			
			return nullptr;
		}
		
		inline unsigned int getSize()
			{ return size; }
			
		inline bool isAvailable(unsigned int slot)
			{ return available[slot]; }
};

#endif