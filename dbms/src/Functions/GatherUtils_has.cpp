#include <Functions/GatherUtils.h>
#include <Functions/GatherUtils_selectors.h>


namespace DB
{

struct ArrayHasSelectArraySourcePair : public ArraySourcePairSelector<ArrayHasSelectArraySourcePair>
{
    template <typename Source, typename Sink>
    static void selectSourcePair(Source && first, Source && second, bool all, ColumnUInt8 & result)
    {
        arrayAllAny<all>(first, second, result);
    }
};

void sliceHas(IArraySource & first, IArraySource & second, bool all, ColumnUInt8 & result)
{
    ArrayHasSelectArraySourcePair::select(first, second, all, result);
}

}
