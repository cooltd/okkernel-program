okkernel-program

## 题目说明

上机笔试编程题目：okkernel的relu算子实现

请通过阅读okkernel指导手册，了解算能1684芯片架构，并使用其中的okkernel指令实现relu算子。

请在okkernel/device/ok_device_relu_contest.c的程序模板内使用C语言编程。

如下所示，您的代码需放置在//TODO至//END之间

```
void relu_contest(const void *args) {
    okk_initialize();
    param_t *param = (param_t *)args;
    // TODO
    (void)param;
    OKKERNEL_LOG("Hello World\n");
    OKKERNEL_LOG("Please program between TODO and END\n");
    // END
    okk_poll();
}
OKKERNEL_FUNC_REGISTER(relu_contest);
```

## 编程说明

### 环境准备

- 下载工程到本地

```
git clone https://github.com/cooltd/okkernel-program.git
```

- 下载交叉编译工具链并配置环境变量


```
$ source prepare_toolchains.sh
```

- OKKernel 依赖以下文件


```
1）header files
okk.h  bmlib_runtime.h

2）libraries
libbmlib.so
```

### 编译

```
$ cd okkernel
```

```
$ make okk USING_CMODEL=1
```

### 运行

```
$ ./build/cmodel/relu  
```

### 参考资料

[okkernel指导手册](https://doc.sophgo.com/docs/2.7.0/docs_latest_release/okkernel/OKKernel_en.pdf)

