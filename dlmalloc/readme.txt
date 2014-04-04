mchunkptr smallbins[(NSMALLBINS+1)*2];
为什么数组大小为66?

32 * 8 + 8 = 264;
0           1       2        3      4       5
prev_foot   head    fd       bk
                  prev_foot  head   fd      bk
因为头节点中不需要prev_foot head这2个字段
所以可以这样覆盖以节省空间.


malloc_chunk(<=256bytes)
malloc_tree_chunk(>256bytes)
malloc_segment(

malloc_state:统一的管理解构体.
                
