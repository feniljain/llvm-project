//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef SUPPORT_TEST_ITERATORS_H
#define SUPPORT_TEST_ITERATORS_H

#include <cassert>
#include <concepts>
#include <iterator>
#include <stdexcept>
#include <utility>

#include "test_macros.h"

template <class It>
class output_iterator
{
    It it_;

    template <class U> friend class output_iterator;
public:
    typedef          std::output_iterator_tag                  iterator_category;
    typedef void                                               value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    TEST_CONSTEXPR output_iterator() : it_() {}
    TEST_CONSTEXPR explicit output_iterator(It it) : it_(std::move(it)) {}
    template <class U>
        TEST_CONSTEXPR output_iterator(const output_iterator<U>& u) : it_(u.it_) {}

    TEST_CONSTEXPR reference operator*() const {return *it_;}

    TEST_CONSTEXPR_CXX14 output_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 output_iterator operator++(int) {return output_iterator(it_++);}

    TEST_CONSTEXPR It base() const {return it_;} // TODO remove me
    friend TEST_CONSTEXPR It base(const output_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

// This is the Cpp17InputIterator requirement as described in Table 87 ([input.iterators]),
// formerly known as InputIterator prior to C++20.
template <class It, class ItTraits = It>
class cpp17_input_iterator
{
    typedef std::iterator_traits<ItTraits> Traits;
    It it_;

    template <class U, class T> friend class cpp17_input_iterator;
public:
    typedef          std::input_iterator_tag                   iterator_category;
    typedef typename Traits::value_type                        value_type;
    typedef typename Traits::difference_type                   difference_type;
    typedef It                                                 pointer;
    typedef typename Traits::reference                         reference;

    TEST_CONSTEXPR explicit cpp17_input_iterator(It it) : it_(it) {}
    template <class U, class T>
        TEST_CONSTEXPR cpp17_input_iterator(const cpp17_input_iterator<U, T>& u) : it_(u.it_) {}

    TEST_CONSTEXPR reference operator*() const {return *it_;}
    TEST_CONSTEXPR pointer operator->() const {return it_;}

    TEST_CONSTEXPR_CXX14 cpp17_input_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 cpp17_input_iterator operator++(int) {return cpp17_input_iterator(it_++);}

    friend TEST_CONSTEXPR bool operator==(const cpp17_input_iterator& x, const cpp17_input_iterator& y) {return x.it_ == y.it_;}
    friend TEST_CONSTEXPR bool operator!=(const cpp17_input_iterator& x, const cpp17_input_iterator& y) {return x.it_ != y.it_;}

    TEST_CONSTEXPR It base() const {return it_;} // TODO remove me
    friend TEST_CONSTEXPR It base(const cpp17_input_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

template <class It>
class forward_iterator
{
    It it_;

    template <class U> friend class forward_iterator;
public:
    typedef          std::forward_iterator_tag                 iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    TEST_CONSTEXPR forward_iterator() : it_() {}
    TEST_CONSTEXPR explicit forward_iterator(It it) : it_(it) {}
    template <class U>
        TEST_CONSTEXPR forward_iterator(const forward_iterator<U>& u) : it_(u.it_) {}

    TEST_CONSTEXPR reference operator*() const {return *it_;}
    TEST_CONSTEXPR pointer operator->() const {return it_;}

    TEST_CONSTEXPR_CXX14 forward_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 forward_iterator operator++(int) {return forward_iterator(it_++);}

    friend TEST_CONSTEXPR bool operator==(const forward_iterator& x, const forward_iterator& y) {return x.it_ == y.it_;}
    friend TEST_CONSTEXPR bool operator!=(const forward_iterator& x, const forward_iterator& y) {return x.it_ != y.it_;}

    TEST_CONSTEXPR It base() const {return it_;} // TODO remove me
    friend TEST_CONSTEXPR It base(const forward_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

template <class It>
class non_default_constructible_iterator
{
    It it_;

    template <class U> friend class non_default_constructible_iterator;
public:
    typedef          std::input_iterator_tag                   iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    non_default_constructible_iterator() = delete;

    TEST_CONSTEXPR explicit non_default_constructible_iterator(It it) : it_(it) {}
    template <class U>
        TEST_CONSTEXPR non_default_constructible_iterator(const non_default_constructible_iterator<U>& u) : it_(u.it_) {}

    TEST_CONSTEXPR reference operator*() const {return *it_;}
    TEST_CONSTEXPR pointer operator->() const {return it_;}

    TEST_CONSTEXPR_CXX14 non_default_constructible_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 non_default_constructible_iterator operator++(int) {return non_default_constructible_iterator(it_++);}

    friend TEST_CONSTEXPR bool operator==(const non_default_constructible_iterator& x, const non_default_constructible_iterator& y) {return x.it_ == y.it_;}
    friend TEST_CONSTEXPR bool operator!=(const non_default_constructible_iterator& x, const non_default_constructible_iterator& y) {return x.it_ != y.it_;}

    template <class T>
    void operator,(T const &) = delete;
};

template <class It>
class bidirectional_iterator
{
    It it_;

    template <class U> friend class bidirectional_iterator;
public:
    typedef          std::bidirectional_iterator_tag           iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    TEST_CONSTEXPR bidirectional_iterator() : it_() {}
    TEST_CONSTEXPR explicit bidirectional_iterator(It it) : it_(it) {}
    template <class U>
        TEST_CONSTEXPR bidirectional_iterator(const bidirectional_iterator<U>& u) : it_(u.it_) {}

    TEST_CONSTEXPR reference operator*() const {return *it_;}
    TEST_CONSTEXPR pointer operator->() const {return it_;}

    TEST_CONSTEXPR_CXX14 bidirectional_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 bidirectional_iterator& operator--() {--it_; return *this;}
    TEST_CONSTEXPR_CXX14 bidirectional_iterator operator++(int) {return bidirectional_iterator(it_++);}
    TEST_CONSTEXPR_CXX14 bidirectional_iterator operator--(int) {return bidirectional_iterator(it_--);}

    friend TEST_CONSTEXPR bool operator==(const bidirectional_iterator& x, const bidirectional_iterator& y) {return x.it_ == y.it_;}
    friend TEST_CONSTEXPR bool operator!=(const bidirectional_iterator& x, const bidirectional_iterator& y) {return x.it_ != y.it_;}

    TEST_CONSTEXPR It base() const {return it_;} // TODO remove me
    friend TEST_CONSTEXPR It base(const bidirectional_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

template <class It>
class random_access_iterator
{
    It it_;

    template <class U> friend class random_access_iterator;
public:
    typedef          std::random_access_iterator_tag           iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;

    TEST_CONSTEXPR random_access_iterator() : it_() {}
    TEST_CONSTEXPR explicit random_access_iterator(It it) : it_(it) {}
    template <class U>
        TEST_CONSTEXPR random_access_iterator(const random_access_iterator<U>& u) : it_(u.it_) {}

    TEST_CONSTEXPR_CXX14 reference operator*() const {return *it_;}
    TEST_CONSTEXPR_CXX14 pointer operator->() const {return it_;}
    TEST_CONSTEXPR_CXX14 reference operator[](difference_type n) const {return it_[n];}

    TEST_CONSTEXPR_CXX14 random_access_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 random_access_iterator& operator--() {--it_; return *this;}
    TEST_CONSTEXPR_CXX14 random_access_iterator operator++(int) {return random_access_iterator(it_++);}
    TEST_CONSTEXPR_CXX14 random_access_iterator operator--(int) {return random_access_iterator(it_--);}

    TEST_CONSTEXPR_CXX14 random_access_iterator& operator+=(difference_type n) {it_ += n; return *this;}
    TEST_CONSTEXPR_CXX14 random_access_iterator& operator-=(difference_type n) {it_ -= n; return *this;}
    friend TEST_CONSTEXPR_CXX14 random_access_iterator operator+(random_access_iterator x, difference_type n) {x += n; return x;}
    friend TEST_CONSTEXPR_CXX14 random_access_iterator operator+(difference_type n, random_access_iterator x) {x += n; return x;}
    friend TEST_CONSTEXPR_CXX14 random_access_iterator operator-(random_access_iterator x, difference_type n) {x -= n; return x;}
    friend TEST_CONSTEXPR difference_type operator-(random_access_iterator x, random_access_iterator y) {return x.it_ - y.it_;}

    friend TEST_CONSTEXPR bool operator==(const random_access_iterator& x, const random_access_iterator& y) {return x.it_ == y.it_;}
    friend TEST_CONSTEXPR bool operator!=(const random_access_iterator& x, const random_access_iterator& y) {return x.it_ != y.it_;}
    friend TEST_CONSTEXPR bool operator< (const random_access_iterator& x, const random_access_iterator& y) {return x.it_ <  y.it_;}
    friend TEST_CONSTEXPR bool operator<=(const random_access_iterator& x, const random_access_iterator& y) {return x.it_ <= y.it_;}
    friend TEST_CONSTEXPR bool operator> (const random_access_iterator& x, const random_access_iterator& y) {return x.it_ >  y.it_;}
    friend TEST_CONSTEXPR bool operator>=(const random_access_iterator& x, const random_access_iterator& y) {return x.it_ >= y.it_;}

    TEST_CONSTEXPR It base() const {return it_;} // TODO remove me
    friend TEST_CONSTEXPR It base(const random_access_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

#if TEST_STD_VER > 17
template <class It>
class contiguous_iterator
{
    static_assert(std::is_pointer_v<It>, "Things probably break in this case");

    It it_;

    template <class U> friend class contiguous_iterator;
public:
    typedef          std::contiguous_iterator_tag              iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;
    typedef typename std::remove_pointer<It>::type             element_type;

    TEST_CONSTEXPR_CXX14 It base() const {return it_;}

    TEST_CONSTEXPR_CXX14 contiguous_iterator() : it_() {}
    TEST_CONSTEXPR_CXX14 explicit contiguous_iterator(It it) : it_(it) {}
    template <class U>
        TEST_CONSTEXPR_CXX14 contiguous_iterator(const contiguous_iterator<U>& u) : it_(u.it_) {}

    TEST_CONSTEXPR reference operator*() const {return *it_;}
    TEST_CONSTEXPR pointer operator->() const {return it_;}
    TEST_CONSTEXPR reference operator[](difference_type n) const {return it_[n];}

    TEST_CONSTEXPR_CXX14 contiguous_iterator& operator++() {++it_; return *this;}
    TEST_CONSTEXPR_CXX14 contiguous_iterator& operator--() {--it_; return *this;}
    TEST_CONSTEXPR_CXX14 contiguous_iterator operator++(int) {return contiguous_iterator(it_++);}
    TEST_CONSTEXPR_CXX14 contiguous_iterator operator--(int) {return contiguous_iterator(it_--);}

    TEST_CONSTEXPR_CXX14 contiguous_iterator& operator+=(difference_type n) {it_ += n; return *this;}
    TEST_CONSTEXPR_CXX14 contiguous_iterator& operator-=(difference_type n) {it_ -= n; return *this;}
    friend TEST_CONSTEXPR_CXX14 contiguous_iterator operator+(contiguous_iterator x, difference_type n) {x += n; return x;}
    friend TEST_CONSTEXPR_CXX14 contiguous_iterator operator+(difference_type n, contiguous_iterator x) {x += n; return x;}
    friend TEST_CONSTEXPR_CXX14 contiguous_iterator operator-(contiguous_iterator x, difference_type n) {x -= n; return x;}
    friend TEST_CONSTEXPR difference_type operator-(contiguous_iterator x, contiguous_iterator y) {return x.it_ - y.it_;}

    friend TEST_CONSTEXPR bool operator==(const contiguous_iterator& x, const contiguous_iterator& y) {return x.it_ == y.it_;}
    friend TEST_CONSTEXPR bool operator!=(const contiguous_iterator& x, const contiguous_iterator& y) {return x.it_ != y.it_;}
    friend TEST_CONSTEXPR bool operator< (const contiguous_iterator& x, const contiguous_iterator& y) {return x.it_ <  y.it_;}
    friend TEST_CONSTEXPR bool operator<=(const contiguous_iterator& x, const contiguous_iterator& y) {return x.it_ <= y.it_;}
    friend TEST_CONSTEXPR bool operator> (const contiguous_iterator& x, const contiguous_iterator& y) {return x.it_ >  y.it_;}
    friend TEST_CONSTEXPR bool operator>=(const contiguous_iterator& x, const contiguous_iterator& y) {return x.it_ >= y.it_;}

    friend TEST_CONSTEXPR It base(const contiguous_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

template <class It>
class three_way_contiguous_iterator
{
    static_assert(std::is_pointer_v<It>, "Things probably break in this case");

    It it_;

    template <class U> friend class three_way_contiguous_iterator;
public:
    typedef          std::contiguous_iterator_tag              iterator_category;
    typedef typename std::iterator_traits<It>::value_type      value_type;
    typedef typename std::iterator_traits<It>::difference_type difference_type;
    typedef It                                                 pointer;
    typedef typename std::iterator_traits<It>::reference       reference;
    typedef typename std::remove_pointer<It>::type             element_type;

    constexpr It base() const {return it_;}

    constexpr three_way_contiguous_iterator() : it_() {}
    constexpr explicit three_way_contiguous_iterator(It it) : it_(it) {}
    template <class U>
    constexpr three_way_contiguous_iterator(const three_way_contiguous_iterator<U>& u) : it_(u.it_) {}

    constexpr reference operator*() const {return *it_;}
    constexpr pointer operator->() const {return it_;}
    constexpr reference operator[](difference_type n) const {return it_[n];}

    constexpr three_way_contiguous_iterator& operator++() {++it_; return *this;}
    constexpr three_way_contiguous_iterator& operator--() {--it_; return *this;}
    constexpr three_way_contiguous_iterator operator++(int) {return three_way_contiguous_iterator(it_++);}
    constexpr three_way_contiguous_iterator operator--(int) {return three_way_contiguous_iterator(it_--);}

    constexpr three_way_contiguous_iterator& operator+=(difference_type n) {it_ += n; return *this;}
    constexpr three_way_contiguous_iterator& operator-=(difference_type n) {it_ -= n; return *this;}
    friend constexpr three_way_contiguous_iterator operator+(three_way_contiguous_iterator x, difference_type n) {x += n; return x;}
    friend constexpr three_way_contiguous_iterator operator+(difference_type n, three_way_contiguous_iterator x) {x += n; return x;}
    friend constexpr three_way_contiguous_iterator operator-(three_way_contiguous_iterator x, difference_type n) {x -= n; return x;}
    friend constexpr difference_type operator-(three_way_contiguous_iterator x, three_way_contiguous_iterator y) {return x.it_ - y.it_;}

    friend constexpr auto operator<=>(const three_way_contiguous_iterator& x, const three_way_contiguous_iterator& y) {return x.it_ <=> y.it_;}
    friend constexpr bool operator==(const three_way_contiguous_iterator& x, const three_way_contiguous_iterator& y) {return x.it_ == y.it_;}

    template <class T>
    void operator,(T const &) = delete;
};
#endif // TEST_STD_VER > 17

template <class Iter> // ADL base() for everything else (including pointers)
TEST_CONSTEXPR Iter base(Iter i) { return i; }

template <typename T>
struct ThrowingIterator {
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t                       difference_type;
    typedef const T                         value_type;
    typedef const T *                       pointer;
    typedef const T &                       reference;

    enum ThrowingAction { TAIncrement, TADecrement, TADereference, TAAssignment, TAComparison };

    TEST_CONSTEXPR ThrowingIterator()
        : begin_(nullptr), end_(nullptr), current_(nullptr), action_(TADereference), index_(0) {}
    TEST_CONSTEXPR explicit ThrowingIterator(const T* first, const T* last, int index = 0,
                                                   ThrowingAction action = TADereference)
        : begin_(first), end_(last), current_(first), action_(action), index_(index) {}
    TEST_CONSTEXPR ThrowingIterator(const ThrowingIterator &rhs)
        : begin_(rhs.begin_), end_(rhs.end_), current_(rhs.current_), action_(rhs.action_), index_(rhs.index_) {}

    TEST_CONSTEXPR_CXX14 ThrowingIterator& operator=(const ThrowingIterator& rhs) {
        if (action_ == TAAssignment && --index_ < 0) {
#ifndef TEST_HAS_NO_EXCEPTIONS
            throw std::runtime_error("throw from iterator assignment");
#else
            assert(false);
#endif
        }
        begin_ = rhs.begin_;
        end_ = rhs.end_;
        current_ = rhs.current_;
        action_ = rhs.action_;
        index_ = rhs.index_;
        return *this;
    }

    TEST_CONSTEXPR_CXX14 reference operator*() const {
        if (action_ == TADereference && --index_ < 0) {
#ifndef TEST_HAS_NO_EXCEPTIONS
            throw std::runtime_error("throw from iterator dereference");
#else
            assert(false);
#endif
        }
        return *current_;
    }

    TEST_CONSTEXPR_CXX14 ThrowingIterator& operator++() {
        if (action_ == TAIncrement && --index_ < 0) {
#ifndef TEST_HAS_NO_EXCEPTIONS
            throw std::runtime_error("throw from iterator increment");
#else
            assert(false);
#endif
        }
        ++current_;
        return *this;
    }

    TEST_CONSTEXPR_CXX14 ThrowingIterator operator++(int) {
        ThrowingIterator temp = *this;
        ++(*this);
        return temp;
    }

    TEST_CONSTEXPR_CXX14 ThrowingIterator& operator--() {
        if (action_ == TADecrement && --index_ < 0) {
#ifndef TEST_HAS_NO_EXCEPTIONS
            throw std::runtime_error("throw from iterator decrement");
#else
            assert(false);
#endif
        }
        --current_;
        return *this;
    }

    TEST_CONSTEXPR_CXX14 ThrowingIterator operator--(int) {
        ThrowingIterator temp = *this;
        --(*this);
        return temp;
    }

    TEST_CONSTEXPR_CXX14 friend bool operator==(const ThrowingIterator& a, const ThrowingIterator& b) {
        if (a.action_ == TAComparison && --a.index_ < 0) {
#ifndef TEST_HAS_NO_EXCEPTIONS
            throw std::runtime_error("throw from iterator comparison");
#else
            assert(false);
#endif
        }
        bool atEndL = a.current_ == a.end_;
        bool atEndR = b.current_ == b.end_;
        if (atEndL != atEndR) return false;  // one is at the end (or empty), the other is not.
        if (atEndL) return true;             // both are at the end (or empty)
        return a.current_ == b.current_;
    }

    TEST_CONSTEXPR friend bool operator!=(const ThrowingIterator& a, const ThrowingIterator& b) {
        return !(a == b);
    }

    template <class T2>
    void operator,(T2 const &) = delete;

private:
    const T* begin_;
    const T* end_;
    const T* current_;
    ThrowingAction action_;
    mutable int index_;
};

template <typename T>
struct NonThrowingIterator {
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t                       difference_type;
    typedef const T                         value_type;
    typedef const T *                       pointer;
    typedef const T &                       reference;

    NonThrowingIterator()
        : begin_(nullptr), end_(nullptr), current_(nullptr) {}
    explicit NonThrowingIterator(const T *first, const T *last)
        : begin_(first), end_(last), current_(first) {}
    NonThrowingIterator(const NonThrowingIterator& rhs)
        : begin_(rhs.begin_), end_(rhs.end_), current_(rhs.current_) {}

    NonThrowingIterator& operator=(const NonThrowingIterator& rhs) TEST_NOEXCEPT {
        begin_ = rhs.begin_;
        end_ = rhs.end_;
        current_ = rhs.current_;
        return *this;
    }

    reference operator*() const TEST_NOEXCEPT {
        return *current_;
    }

    NonThrowingIterator& operator++() TEST_NOEXCEPT {
        ++current_;
        return *this;
    }

    NonThrowingIterator operator++(int) TEST_NOEXCEPT {
        NonThrowingIterator temp = *this;
        ++(*this);
        return temp;
    }

    NonThrowingIterator & operator--() TEST_NOEXCEPT {
        --current_;
        return *this;
    }

    NonThrowingIterator operator--(int) TEST_NOEXCEPT {
        NonThrowingIterator temp = *this;
        --(*this);
        return temp;
    }

    friend bool operator==(const NonThrowingIterator& a, const NonThrowingIterator& b) TEST_NOEXCEPT {
        bool atEndL = a.current_ == a.end_;
        bool atEndR = b.current_ == b.end_;
        if (atEndL != atEndR) return false;  // one is at the end (or empty), the other is not.
        if (atEndL) return true;             // both are at the end (or empty)
        return a.current_ == b.current_;
    }

    friend bool operator!=(const NonThrowingIterator& a, const NonThrowingIterator& b) TEST_NOEXCEPT {
        return !(a == b);
    }

    template <class T2>
    void operator,(T2 const &) = delete;

private:
    const T *begin_;
    const T *end_;
    const T *current_;
};

#ifdef TEST_SUPPORTS_RANGES
template <class It>
class cpp20_input_iterator
{
    It it_;

public:
    using value_type = std::iter_value_t<It>;
    using difference_type = std::iter_difference_t<It>;
    using iterator_concept = std::input_iterator_tag;

    constexpr explicit cpp20_input_iterator(It it) : it_(it) {}
    cpp20_input_iterator(cpp20_input_iterator&&) = default;
    cpp20_input_iterator& operator=(cpp20_input_iterator&&) = default;
    constexpr decltype(auto) operator*() const { return *it_; }
    constexpr cpp20_input_iterator& operator++() { ++it_; return *this; }
    constexpr void operator++(int) { ++it_; }

    constexpr const It& base() const& { return it_; } // TODO remove me
    friend constexpr It base(const cpp20_input_iterator& i) { return i.it_; }

    template <class T>
    void operator,(T const &) = delete;
};

template<std::input_or_output_iterator>
struct iter_value_or_void { using type = void; };

template<std::input_iterator I>
struct iter_value_or_void<I> {
    using type = std::iter_value_t<I>;
};

// Iterator adaptor that counts the number of times the iterator has had a successor/predecessor
// operation called. Has two recorders:
// * `stride_count`, which records the total number of calls to an op++, op--, op+=, or op-=.
// * `stride_displacement`, which records the displacement of the calls. This means that both
//   op++/op+= will increase the displacement counter by 1, and op--/op-= will decrease the
//   displacement counter by 1.
template <class It>
class stride_counting_iterator {
public:
    using value_type = typename iter_value_or_void<It>::type;
    using difference_type = std::iter_difference_t<It>;
    using iterator_concept =
        std::conditional_t<std::contiguous_iterator<It>,    std::contiguous_iterator_tag,
        std::conditional_t<std::random_access_iterator<It>, std::random_access_iterator_tag,
        std::conditional_t<std::bidirectional_iterator<It>, std::bidirectional_iterator_tag,
        std::conditional_t<std::forward_iterator<It>,       std::forward_iterator_tag,
        std::conditional_t<std::input_iterator<It>,         std::input_iterator_tag,
        /* else */                                          std::output_iterator_tag
    >>>>>;

    stride_counting_iterator() requires std::default_initializable<It> = default;

    constexpr explicit stride_counting_iterator(It const& it) : base_(base(it)) { }

    friend constexpr It base(stride_counting_iterator const& it) { return It(it.base_); }

    constexpr difference_type stride_count() const { return stride_count_; }

    constexpr difference_type stride_displacement() const { return stride_displacement_; }

    constexpr decltype(auto) operator*() const { return *It(base_); }

    constexpr decltype(auto) operator[](difference_type n) const { return It(base_)[n]; }

    constexpr stride_counting_iterator& operator++() {
        It tmp(base_);
        base_ = base(++tmp);
        ++stride_count_;
        ++stride_displacement_;
        return *this;
    }

    constexpr void operator++(int) { ++*this; }

    constexpr stride_counting_iterator operator++(int)
        requires std::forward_iterator<It>
    {
        auto temp = *this;
        ++*this;
        return temp;
    }

    constexpr stride_counting_iterator& operator--()
        requires std::bidirectional_iterator<It>
    {
        It tmp(base_);
        base_ = base(--tmp);
        ++stride_count_;
        --stride_displacement_;
        return *this;
    }

    constexpr stride_counting_iterator operator--(int)
        requires std::bidirectional_iterator<It>
    {
        auto temp = *this;
        --*this;
        return temp;
    }

    constexpr stride_counting_iterator& operator+=(difference_type const n)
        requires std::random_access_iterator<It>
    {
        It tmp(base_);
        base_ = base(tmp += n);
        ++stride_count_;
        ++stride_displacement_;
        return *this;
    }

    constexpr stride_counting_iterator& operator-=(difference_type const n)
        requires std::random_access_iterator<It>
    {
        It tmp(base_);
        base_ = base(tmp -= n);
        ++stride_count_;
        --stride_displacement_;
        return *this;
    }

    friend constexpr stride_counting_iterator operator+(stride_counting_iterator it, difference_type n)
        requires std::random_access_iterator<It>
    {
        return it += n;
    }

    friend constexpr stride_counting_iterator operator+(difference_type n, stride_counting_iterator it)
        requires std::random_access_iterator<It>
    {
        return it += n;
    }

    friend constexpr stride_counting_iterator operator-(stride_counting_iterator it, difference_type n)
        requires std::random_access_iterator<It>
    {
        return it -= n;
    }

    friend constexpr difference_type operator-(stride_counting_iterator const& x, stride_counting_iterator const& y)
        requires std::sized_sentinel_for<It, It>
    {
        return base(x) - base(y);
    }

    constexpr bool operator==(stride_counting_iterator const& other) const
        requires std::sentinel_for<It, It>
    {
        return It(base_) == It(other.base_);
    }

    friend constexpr bool operator<(stride_counting_iterator const& x, stride_counting_iterator const& y)
        requires std::random_access_iterator<It>
    {
        return It(x.base_) < It(y.base_);
    }

    friend constexpr bool operator>(stride_counting_iterator const& x, stride_counting_iterator const& y)
        requires std::random_access_iterator<It>
    {
        return It(x.base_) > It(y.base_);
    }

    friend constexpr bool operator<=(stride_counting_iterator const& x, stride_counting_iterator const& y)
        requires std::random_access_iterator<It>
    {
        return It(x.base_) <= It(y.base_);
    }

    friend constexpr bool operator>=(stride_counting_iterator const& x, stride_counting_iterator const& y)
        requires std::random_access_iterator<It>
    {
        return It(x.base_) >= It(y.base_);
    }

    template <class T>
    void operator,(T const &) = delete;

private:
    decltype(base(std::declval<It>())) base_;
    difference_type stride_count_ = 0;
    difference_type stride_displacement_ = 0;
};
#endif // TEST_SUPPORTS_RANGES

#if TEST_STD_VER > 17
template <class It>
class sentinel_wrapper {
public:
    explicit sentinel_wrapper() = default;
    constexpr explicit sentinel_wrapper(const It& it) : base_(base(it)) {}
    constexpr bool operator==(const It& other) const { return base_ == base(other); }
    friend constexpr It base(const sentinel_wrapper& s) { return It(s.base_); }
private:
    decltype(base(std::declval<It>())) base_;
};

template <class It>
class sized_sentinel {
public:
    explicit sized_sentinel() = default;
    constexpr explicit sized_sentinel(const It& it) : base_(base(it)) {}
    constexpr bool operator==(const It& other) const { return base_ == base(other); }
    friend constexpr auto operator-(const sized_sentinel& s, const It& i) { return s.base_ - base(i); }
    friend constexpr auto operator-(const It& i, const sized_sentinel& s) { return base(i) - s.base_; }
    friend constexpr It base(const sized_sentinel& s) { return It(s.base_); }
private:
    decltype(base(std::declval<It>())) base_;
};
#endif // TEST_STD_VER > 17

#endif // SUPPORT_TEST_ITERATORS_H
