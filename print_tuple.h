#ifndef AUX_PRINT_TUPLE_H
#define AUX_PRINT_TUPLE_H

#include <iostream>
#include <tuple>

namespace aux {
template<std::size_t...>
struct seq {
};

template<std::size_t N, std::size_t... Is>
struct gen_seq : gen_seq<N - 1, N - 1, Is...> {
};

template<std::size_t... Is>
struct gen_seq<0, Is...> : seq<Is...> {
};

template<class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple(std::basic_ostream<Ch, Tr> &os, Tuple const &t, seq<Is...>) {
    using swallow = int[];
    (void) swallow{0, (void(os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), 0)...};
}
}

#endif //AUX_PRINT_TUPLE_H
