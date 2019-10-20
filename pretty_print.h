#ifndef AUX_PRETTY_PRINT_H
#define AUX_PRETTY_PRINT_H

#include "aux/print_tuple.h"

template<class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr> &os, std::tuple<Args...> const &t)
-> std::basic_ostream<Ch, Tr> & {
    os << "(";
    aux::print_tuple(os, t, aux::gen_seq<sizeof...(Args)>());
    return os << ")";
}

#endif //AUX_PRETTY_PRINT_H
