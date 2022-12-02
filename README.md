# okkernel-program

## 使用手册

### 环境准备

For the first time, you should download cross toolchains and set CROSS_TOOLCHAINS variable

```
$ source prepare_toolchains.sh
```

OKKernel depends on the following files

1）header files
okk.h  bmlib_runtime.h

2）libraries
libbmlib.so

### 编译

```
$ cd okkernel
```

```
$ make okk USING_CMODEL=1
```

### 运行

```
$ export LD_LIBRARY_PATH=/path/to/lib/
```

```
$ ./build/cmodel/relu  
```

