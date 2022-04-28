/*
 * Copyright (C) 2022 Fondazione Istituto Italiano di Tecnologia
 *
 * This software may be modified and distributed under the terms of the
 * BSD-2-Clause license (https://opensource.org/licenses/BSD-2-Clause).
 */

#ifndef MATIOCPP_EIGENCONVERSIONS_H
#define MATIOCPP_EIGENCONVERSIONS_H

#include <matioCpp/ForwardDeclarations.h>

#ifdef MATIOCPP_HAS_EIGEN

#include <matioCpp/Vector.h>
#include <matioCpp/MultiDimensionalArray.h>

#include <Eigen/Core>

namespace matioCpp
{

/**
 * @brief Conversion from a MultiDimensionalArray to an Eigen matrix
 * @param input The MultiDimensionalArray
 * @return A map from the internal data of the MultiDimensionalArray
 */
template <typename type>
inline Eigen::Map<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> to_eigen(MultiDimensionalArray<type>& input);

/**
 * @brief Conversion from a const MultiDimensionalArray to an Eigen matrix
 * @param input The MultiDimensionalArray
 * @return A const map from the internal data of the MultiDimensionalArray
 */
template <typename type>
inline const Eigen::Map<Eigen::Matrix<type, Eigen::Dynamic, Eigen::Dynamic>> to_eigen(const MultiDimensionalArray<type>& input);

/**
 * @brief Conversion from a Vector to an Eigen vector
 * @param input The Vector
 * @return A map from the internal data of the Vector
 */
template <typename type>
inline Eigen::Map<Eigen::Matrix<type, Eigen::Dynamic, 1>> to_eigen(Vector<type>& input);

/**
 * @brief Conversion from a const Vector to an Eigen vector
 * @param input The Vector
 * @return A const map from the internal data of the Vector
 */
template <typename type>
inline const Eigen::Map<Eigen::Matrix<type, Eigen::Dynamic, 1>> to_eigen(const Vector<type>& input);

/**
 * @brief Conversion from an Eigen matrix to a MultiDimensionalArray
 * @param name The name of the resulting matioCpp variable.
 * @param input The input matrix.
 * @return A MultiDimensionalArray containing a copy of the input data
 */
template <typename EigenDerived, typename = std::enable_if_t<Eigen::MatrixBase<EigenDerived>::RowsAtCompileTime != 1 &&
                                                             Eigen::MatrixBase<EigenDerived>::ColsAtCompileTime != 1>>
inline MultiDimensionalArray<typename EigenDerived::Scalar> make_variable(const std::string& name, const Eigen::MatrixBase<EigenDerived>& input);

}

#include "impl/EigenConversions.tpp"

#endif


#endif // MATIOCPP_EIGENCONVERSIONS_H
