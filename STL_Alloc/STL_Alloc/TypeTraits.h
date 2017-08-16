#pragma once

struct TrueType
{};

struct FalseType
{};

template<class T>
struct TypeTraits
{
	typedef FalseType    hasTrivialDefaultConstructor;
	typedef FalseType    hasTrivialCopyConstructor;
	typedef FalseType    hasTrivialAssignmentOperator;
	typedef FalseType    hasTrivialDestructor;
	typedef FalseType    isPODType;
};

template<class T>
struct TypeTraits<T*>
{
	typedef TrueType   hasTrivialDefaultConstructor;
	typedef TrueType   hasTrivialCopyConstructor;
	typedef TrueType   hasTrivialAssignmentOperator;
	typedef TrueType   hasTrivialDestructor;
	typedef TrueType   isPODType;
};


template<>
struct TypeTraits<int>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<signed char>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<unsigned char>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};


template<>
struct TypeTraits<short>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<unsigned short>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<unsigned int>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<unsigned long>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<float>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType    hasTrivialDefaultConstructor;
	typedef TrueType    hasTrivialCopyConstructor;
	typedef TrueType    hasTrivialAssignmentOperator;
	typedef TrueType    hasTrivialDestructor;
	typedef TrueType    isPODType;
};