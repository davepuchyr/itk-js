/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include <emscripten.h>
#include <emscripten/bind.h>

#include "itkTIFFImageIO.h"

#include "itkImageIOBaseJSBinding.h"

typedef itk::ImageIOBaseJSBinding< itk::TIFFImageIO > TIFFImageIOJSBindingType;

EMSCRIPTEN_BINDINGS(itk_tiff_image_io_js_binding) {
  emscripten::register_vector<double>("AxisDirectionType");
  emscripten::enum_<TIFFImageIOJSBindingType::IOPixelType>("IOPixelType")
    .value("UNKNOWNPIXELTYPE", itk::ImageIOBase::UNKNOWNPIXELTYPE)
    .value("SCALAR", itk::ImageIOBase::SCALAR)
    .value("RGB", itk::ImageIOBase::RGB)
    .value("RGBA", itk::ImageIOBase::RGBA)
    .value("OFFSET", itk::ImageIOBase::OFFSET)
    .value("VECTOR", itk::ImageIOBase::VECTOR)
    .value("POINT", itk::ImageIOBase::POINT)
    .value("COVARIANTVECTOR", itk::ImageIOBase::COVARIANTVECTOR)
    .value("SYMMETRICSECONDRANKTENSOR", itk::ImageIOBase::SYMMETRICSECONDRANKTENSOR)
    .value("DIFFUSIONTENSOR3D", itk::ImageIOBase::DIFFUSIONTENSOR3D)
    .value("COMPLEX", itk::ImageIOBase::COMPLEX)
    .value("FIXEDARRAY", itk::ImageIOBase::FIXEDARRAY)
    .value("MATRIX", itk::ImageIOBase::MATRIX)
    ;
  emscripten::enum_<TIFFImageIOJSBindingType::IOComponentType>("IOComponentType")
    .value("UNKNOWNCOMPONENTTYPE", itk::ImageIOBase::UNKNOWNCOMPONENTTYPE)
    .value("UCHAR", itk::ImageIOBase::UCHAR)
    .value("CHAR", itk::ImageIOBase::CHAR)
    .value("USHORT", itk::ImageIOBase::USHORT)
    .value("SHORT", itk::ImageIOBase::SHORT)
    .value("UINT", itk::ImageIOBase::UINT)
    .value("INT", itk::ImageIOBase::INT)
    .value("ULONG", itk::ImageIOBase::ULONG)
    .value("LONG", itk::ImageIOBase::LONG)
    .value("ULONGLONG", itk::ImageIOBase::ULONGLONG)
    .value("LONGLONG", itk::ImageIOBase::LONGLONG)
    .value("FLOAT", itk::ImageIOBase::FLOAT)
    .value("DOUBLE", itk::ImageIOBase::DOUBLE)
    ;
  emscripten::class_<TIFFImageIOJSBindingType>("ITKImageIO")
  .constructor<>()
  .function("SetNumberOfDimensions", &TIFFImageIOJSBindingType::SetNumberOfDimensions)
  .function("GetNumberOfDimensions", &TIFFImageIOJSBindingType::GetNumberOfDimensions)
  .function("SetFileName", &TIFFImageIOJSBindingType::SetFileName)
  .function("GetFileName", &TIFFImageIOJSBindingType::GetFileName)
  .function("CanReadFile", &TIFFImageIOJSBindingType::CanReadFile)
  .function("CanWriteFile", &TIFFImageIOJSBindingType::CanWriteFile)
  .function("ReadImageInformation", &TIFFImageIOJSBindingType::ReadImageInformation)
  .function("WriteImageInformation", &TIFFImageIOJSBindingType::WriteImageInformation)
  .function("SetDimensions", &TIFFImageIOJSBindingType::SetDimensions)
  .function("GetDimensions", &TIFFImageIOJSBindingType::GetDimensions)
  .function("SetOrigin", &TIFFImageIOJSBindingType::SetOrigin)
  .function("GetOrigin", &TIFFImageIOJSBindingType::GetOrigin)
  .function("SetSpacing", &TIFFImageIOJSBindingType::SetSpacing)
  .function("GetSpacing", &TIFFImageIOJSBindingType::GetSpacing)
  .function("SetDirection", &TIFFImageIOJSBindingType::SetDirection)
  .function("GetDirection", &TIFFImageIOJSBindingType::GetDirection)
  .function("GetDefaultDirection", &TIFFImageIOJSBindingType::GetDefaultDirection)
  .function("SetPixelType", &TIFFImageIOJSBindingType::SetPixelType)
  .function("GetPixelType", &TIFFImageIOJSBindingType::GetPixelType)
  .function("SetComponentType", &TIFFImageIOJSBindingType::SetComponentType)
  .function("GetComponentType", &TIFFImageIOJSBindingType::GetComponentType)
  .function("GetImageSizeInPixels", &TIFFImageIOJSBindingType::GetImageSizeInPixels)
  .function("GetImageSizeInBytes", &TIFFImageIOJSBindingType::GetImageSizeInBytes)
  .function("GetImageSizeInComponents", &TIFFImageIOJSBindingType::GetImageSizeInComponents)
  .function("SetNumberOfComponents", &TIFFImageIOJSBindingType::SetNumberOfComponents)
  .function("GetNumberOfComponents", &TIFFImageIOJSBindingType::GetNumberOfComponents)
  .function("Read", &TIFFImageIOJSBindingType::Read)
  .function("Write", &TIFFImageIOJSBindingType::Write)
  .function("SetUseCompression", &TIFFImageIOJSBindingType::SetUseCompression)
  ;
}
