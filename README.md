# Huffman Compression

## Getting Started
To build the executable file, navigate to the build directory and run:

```sh
cd build
make
```

## Compression
To compress a file, use the following command:

```sh
hc -z <fileName> <binaryFile>
```

## Decompression
To decompress a file, use the following command:

```sh
hc -uz <treeSerializationFile> <binaryFile> <outputFile>
```

## Help
For a list of available commands, use:

```sh
hc -h
```
