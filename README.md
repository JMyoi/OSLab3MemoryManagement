As programs are moved into and out of memory at runtime, the memory space becomes a checkerboard of free and occupied areas of different sizes. The OS keeps track of all free spaces, 
referred to as holes, and must find a hole of appropriate size whenever a new program component is to be loaded into memory. The OS must also coalesce any neighboring holes resulting from the removal of programs from memory to prevent the memory from becoming a fragmented collection of increasingly smaller holes.

Different search strategies have been explored:
- First-fit (Fixed partition) always starts the search from the beginning of the list and allocates the first hole large enough to accommodate the request.
- Next-fit starts each search at the point of the last allocation.
- Best-fit searches the entire list and chooses the smallest hole large enough to accommodate the request.
- Worst-fit (Dynamic partition) takes the opposite approach from best-fit by always choosing the largest available hole for any request. 
