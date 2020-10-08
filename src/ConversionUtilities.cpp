/*
 * Copyright (C) 2020 Fondazione Istituto Italiano di Tecnologia
 *
 * Licensed under either the GNU Lesser General Public License v3.0 :
 * https://www.gnu.org/licenses/lgpl-3.0.html
 * or the GNU Lesser General Public License v2.1 :
 * https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
 * at your option.
 */

#include <matioCpp/ConversionUtilities.h>

bool matioCpp::get_matio_types(const matioCpp::VariableType &inputVariableType, const matioCpp::ValueType &inputValueType, matio_classes &outputMatioClasses, matio_types &outputMatioType)
{
    if (inputVariableType == VariableType::Element ||
        inputVariableType == VariableType::Vector ||
        inputVariableType == VariableType::MultiDimensionalArray)
    {
        switch (inputValueType)
        {
        case matioCpp::ValueType::INT8:
            outputMatioClasses = matio_classes::MAT_C_INT8;
            outputMatioType =  matio_types::MAT_T_INT8;
            break;
        case matioCpp::ValueType::UINT8:
            outputMatioClasses = matio_classes::MAT_C_UINT8;
            outputMatioType =  matio_types::MAT_T_UINT8;
            break;
        case matioCpp::ValueType::INT16:
            outputMatioClasses = matio_classes::MAT_C_INT16;
            outputMatioType =  matio_types::MAT_T_INT16;
            break;
        case matioCpp::ValueType::UINT16:
            outputMatioClasses = matio_classes::MAT_C_UINT16;
            outputMatioType =  matio_types::MAT_T_UINT16;
            break;
        case matioCpp::ValueType::INT32:
            outputMatioClasses = matio_classes::MAT_C_INT32;
            outputMatioType =  matio_types::MAT_T_INT32;
            break;
        case matioCpp::ValueType::UINT32:
            outputMatioClasses = matio_classes::MAT_C_UINT32;
            outputMatioType =  matio_types::MAT_T_UINT32;
            break;
        case matioCpp::ValueType::SINGLE:
            outputMatioClasses = matio_classes::MAT_C_SINGLE;
            outputMatioType =  matio_types::MAT_T_SINGLE;
            break;
        case matioCpp::ValueType::DOUBLE:
            outputMatioClasses = matio_classes::MAT_C_DOUBLE;
            outputMatioType =  matio_types::MAT_T_DOUBLE;
            break;
        case matioCpp::ValueType::INT64:
            outputMatioClasses = matio_classes::MAT_C_INT64;
            outputMatioType =  matio_types::MAT_T_INT64;
            break;
        case matioCpp::ValueType::UINT64:
            outputMatioClasses = matio_classes::MAT_C_UINT64;
            outputMatioType =  matio_types::MAT_T_UINT64;
            break;
        case matioCpp::ValueType::UTF8:
            outputMatioClasses = matio_classes::MAT_C_CHAR;
            outputMatioType =  matio_types::MAT_T_UTF8;
            break;
        case matioCpp::ValueType::UTF16:
            outputMatioClasses = matio_classes::MAT_C_CHAR;
            outputMatioType =  matio_types::MAT_T_UTF16;
            break;
        case matioCpp::ValueType::UTF32:
            outputMatioClasses = matio_classes::MAT_C_CHAR;
            outputMatioType =  matio_types::MAT_T_UTF32;
            break;
        case matioCpp::ValueType::STRING:
            outputMatioClasses = matio_classes::MAT_C_CHAR;
            outputMatioType =  matio_types::MAT_T_STRING;
            break;
        default:
            return false;
        }
    }
    else if (inputVariableType == VariableType::Struct || inputVariableType == VariableType::VariableArray)
    {
        outputMatioClasses = matio_classes::MAT_C_STRUCT;
        outputMatioType =  matio_types::MAT_T_STRUCT;
    }
    else if (inputVariableType == VariableType::CellArray)
    {
        outputMatioClasses = matio_classes::MAT_C_CELL;
        outputMatioType = MAT_T_CELL;
    }
    else
    {
        return false;
    }

    return true;
}

bool matioCpp::get_types_from_matvart(const matvar_t *input, matioCpp::VariableType &outputVariableType, matioCpp::ValueType &outputValueType)
{
    if (!input)
    {
        return false;
    }

    switch (input->data_type)
    {
    case matio_types::MAT_T_INT8:
        outputValueType = matioCpp::ValueType::INT8;
        break;
    case matio_types::MAT_T_UINT8:
        outputValueType = matioCpp::ValueType::UINT8;
        break;
    case matio_types::MAT_T_INT16:
        outputValueType = matioCpp::ValueType::INT16;
        break;
    case matio_types::MAT_T_UINT16:
        outputValueType = matioCpp::ValueType::UINT16;
        break;
    case matio_types::MAT_T_INT32:
        outputValueType = matioCpp::ValueType::INT32;
        break;
    case matio_types::MAT_T_UINT32:
        outputValueType = matioCpp::ValueType::UINT32;
        break;
    case matio_types::MAT_T_SINGLE:
        outputValueType = matioCpp::ValueType::SINGLE;
        break;
    case matio_types::MAT_T_DOUBLE:
        outputValueType = matioCpp::ValueType::DOUBLE;
        break;
    case matio_types::MAT_T_INT64:
        outputValueType = matioCpp::ValueType::INT64;
        break;
    case matio_types::MAT_T_UINT64:
        outputValueType = matioCpp::ValueType::UINT64;
        break;
    case matio_types::MAT_T_UTF8:
        outputValueType = matioCpp::ValueType::UTF8;
        break;
    case matio_types::MAT_T_UTF16:
        outputValueType = matioCpp::ValueType::UTF16;
        break;
    case matio_types::MAT_T_UTF32:
        outputValueType = matioCpp::ValueType::UTF32;
        break;
    case matio_types::MAT_T_STRING:
        outputValueType = matioCpp::ValueType::STRING;
        break;
    case matio_types::MAT_T_CELL:
    case matio_types::MAT_T_STRUCT:
    case matio_types::MAT_T_ARRAY:
    case matio_types::MAT_T_MATRIX:
        outputValueType = matioCpp::ValueType::VARIABLE;
        break;
    case matio_types::MAT_T_COMPRESSED:
    case matio_types::MAT_T_FUNCTION:
    case matio_types::MAT_T_UNKNOWN:
        outputValueType = matioCpp::ValueType::UNSUPPORTED;
        break;
    }

    if ((input->class_type == matio_classes::MAT_C_OBJECT) ||
        (input->class_type == matio_classes::MAT_C_SPARSE) ||
        (input->class_type == matio_classes::MAT_C_FUNCTION) ||
        (input->class_type == matio_classes::MAT_C_OPAQUE) ||
        (outputValueType == matioCpp::ValueType::UNSUPPORTED) ||
        (input->rank < 2)) //Matio requires the rank to be at least 2
    {
        outputVariableType = matioCpp::VariableType::Unsupported;
        return true;
    }

    size_t dimensionsProduct = 1;
    for (int i = 0; i < input->rank; ++i)
    {
        dimensionsProduct *= input->dims[i];
    }

    if (input->class_type == matio_classes::MAT_C_CELL || input->data_type == matio_types::MAT_T_CELL)
    {
        outputVariableType = matioCpp::VariableType::CellArray;
    }
    else if (dimensionsProduct == 1)
    {
        if (input->data_type == matio_types::MAT_T_STRUCT)
        {
            outputVariableType = matioCpp::VariableType::Struct;
        }
        else if ((input->data_type == MAT_T_ARRAY) || (input->data_type == MAT_T_MATRIX)) //This would be a weird case where the variable has dimension 1x1, it is not a cell nor a struct, yet it contains an array
        {
            outputVariableType = matioCpp::VariableType::VariableArray;
        }
        else
        {
            outputVariableType = matioCpp::VariableType::Element;
        }
    }
    else
    {
        if ((input->data_type == matio_types::MAT_T_STRUCT) || (input->data_type == MAT_T_ARRAY) || (input->data_type == MAT_T_MATRIX))
        {
            outputVariableType = matioCpp::VariableType::VariableArray;
        }
        else if ((input->rank == 2) && ((input->dims[0] == 1) || (input->dims[1] == 1)))
        {
            outputVariableType = matioCpp::VariableType::Vector;
        }
        else
        {
            outputVariableType = matioCpp::VariableType::MultiDimensionalArray;
        }
    }

    return true;
}
