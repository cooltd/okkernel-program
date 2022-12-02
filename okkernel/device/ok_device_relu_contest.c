#include "okk.h"
#ifndef NULL
#define NULL 0
#endif
#define DIV_UP(a, b) (((a) - 1) / (b) + 1)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define LOCAL_MEM_SIZE okk_local_mem_size_per_npu()
#define NPU_NUM okk_npu_num()
#define NO_USE 0
typedef struct {
    int N, C, H, W;
    unsigned long long output_addr;
    unsigned long long input_addr;
} __attribute__((packed)) param_t;

void relu_contest(const void *args) {
    okk_initialize();
    param_t *param = (param_t *)args;
    float C = 0;
    dim4 shape = {.n=param->N, .c=param->C, .h=param->H, .w=param->W};
    local_addr_t tensor1_addr = 0;
    local_addr_t tensor2_addr = shape.n * shape.c * shape.h * shape.w *sizeof(float);
    okk_gdma_32bit_cpy_S2L(tensor1_addr, param->input_addr,  &shape, NULL, NULL);
    okk_bdc_max_C(tensor2_addr, tensor1_addr,  C, &shape, NULL, NULL);
    okk_gdma_32bit_cpy_L2S(param->output_addr, tensor2_addr, &shape, NULL, NULL);
    // TODO
    okk_poll();
}
OKKERNEL_FUNC_REGISTER(relu_contest);
