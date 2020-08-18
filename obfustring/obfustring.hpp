#pragma once

#include <iostream>
#include <array>

namespace obf {
    template<std::size_t N>
    struct obfustring {
        std::array<char, N> m_chars;

        inline auto operator()() {
            std::string str{};
            std::transform(m_chars.begin(), m_chars.end(), std::back_inserter(str), [](auto const& c) {
                return c ^ N;
                });
            return str;
        }

        constexpr obfustring(const char(&data)[N]) : m_chars{} {
            auto it = m_chars.begin();
            for (auto const& c : data) {
                *it = c ^ N;
                it++;
            }
        }
    };
}

#define obf(data) [](){ static auto _ = obf::obfustring<sizeof(data)/sizeof(char)>{data}; return _(); }();