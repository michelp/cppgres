#pragma once

#include <optional>
#include <string>
#include <utility>

#include "datum.h"
#include "type.h"

namespace cppgres {

template <> bool type::is<bool>() { return oid == BOOLOID; }

template <> bool type::is<int64_t>() { return oid == INT8OID || oid == INT4OID || oid == INT2OID; }

template <> bool type::is<int32_t>() { return oid == INT4OID || oid == INT2OID; }

template <> bool type::is<int16_t>() { return oid == INT2OID; }

template <> bool type::is<int8_t>() { return oid == INT2OID; }

template <> bool type::is<std::string_view>() { return oid == TEXTOID; }
template <> bool type::is<byte_array>() { return oid == BYTEAOID; }

template <> constexpr type type_for<int64_t>() { return type{.oid = INT8OID}; }
template <> constexpr type type_for<int32_t>() { return type{.oid = INT4OID}; }
template <> constexpr type type_for<int16>() { return type{.oid = INT2OID}; }
template <> constexpr type type_for<bool>() { return type{.oid = BOOLOID}; }
template <> constexpr type type_for<byte_array>() { return type{.oid = BYTEAOID}; }

template <> datum into_datum(int64_t &t) { return datum(static_cast<::Datum>(t)); }
template <> datum into_datum(int32_t &t) { return datum(static_cast<::Datum>(t)); }
template <> datum into_datum(int16_t &t) { return datum(static_cast<::Datum>(t)); }
template <> datum into_datum(bool &t) { return datum(static_cast<::Datum>(t)); }

template <> int64_t from_datum(datum &d) { return static_cast<int64_t>(d.operator ::Datum &()); }
template <> int32_t from_datum(datum &d) { return static_cast<int32_t>(d.operator ::Datum &()); }
template <> int16_t from_datum(datum &d) { return static_cast<int16_t>(d.operator ::Datum &()); }
template <> bool from_datum(datum &d) { return static_cast<bool>(d.operator ::Datum &()); }
template <> text from_datum(datum &d) { return {d}; }
template <> bytea from_datum(datum &d) { return {d}; }

} // namespace cppgres
