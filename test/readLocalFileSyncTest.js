import test from 'ava'
import path from 'path'

const IntTypes = require(path.resolve(__dirname, '..', 'dist', 'IntTypes.js'))
const FloatTypes = require(path.resolve(__dirname, '..', 'dist', 'FloatTypes.js'))
const PixelTypes = require(path.resolve(__dirname, '..', 'dist', 'PixelTypes.js'))
const readLocalFileSync = require(path.resolve(__dirname, '..', 'dist', 'readLocalFileSync.js'))

const testImageFilePath = path.resolve(__dirname, '..', 'build', 'ExternalData', 'test', 'Input', 'cthead1.png')
const testMeshFilePath = path.resolve(__dirname, '..', 'build', 'ExternalData', 'test', 'Input', 'cow.vtk')

test('readLocalFileSync reads an image file path given on the local filesystem', (t) => {
  const image = readLocalFileSync(testImageFilePath)
  t.is(image.imageType.dimension, 2)
  t.is(image.imageType.componentType, IntTypes.UInt8)
  t.is(image.imageType.pixelType, PixelTypes.RGB)
  t.is(image.imageType.components, 3)
  t.is(image.origin[0], 0.0)
  t.is(image.origin[1], 0.0)
  t.is(image.spacing[0], 1.0)
  t.is(image.spacing[1], 1.0)
  t.is(image.direction.getElement(0, 0), 1.0)
  t.is(image.direction.getElement(0, 1), 0.0)
  t.is(image.direction.getElement(1, 0), 0.0)
  t.is(image.direction.getElement(1, 1), 1.0)
  t.is(image.size[0], 256)
  t.is(image.size[1], 256)
  t.is(image.data.length, 196608)
})

test('readLocalFileSync reads a mesh on the local filesystem', (t) => {
  const mesh = readLocalFileSync(testMeshFilePath)
  t.is(mesh.meshType.dimension, 3)
  t.is(mesh.meshType.pointComponentType, FloatTypes.Float32)
  t.is(mesh.meshType.cellComponentType, IntTypes.UInt32)
  t.is(mesh.meshType.pointPixelType, 1)
  t.is(mesh.meshType.cellPixelType, 1)
  t.is(mesh.numberOfPoints, 2903)
  t.is(mesh.numberOfCells, 3263)
})
