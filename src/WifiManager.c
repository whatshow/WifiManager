/*** 引入头文件 ***/
/*** 基础头文件 ***/
#include <stdio.h>
#include <unistd.h>
/*** 导入linux网络包 ***/
#include <linux/ip.h>
#include <linux/kernel.h>
//#include <linux/module.h>
/*** 导入netfilter框架 ***/
#include <netinet/in.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
//#include <linux/init.h>
/*** 文件操作 ***/
#include <sys/stat.h>
#include <sys/types.h>

/*** 定义常量 ***/
#define URL_MAX_LEN 168                     //URL 最大长度

/*** 预定义函数 ***/
int help(int argc,char *argv[]);            //显示帮助信息
void incorrentArguments();                  //没有匹配的参数

//主函数
int main(int argc,char *argv[])
{
    int isArgumentsLegal = 0;
    //尝试显示帮助
    isArgumentsLegal += help(argc, argv);

    //没有匹配的参数
    if(isArgumentsLegal == 0){
        incorrentArguments();
    }
    return 0;
}
/**
 * 显示帮助信息
 * @return 0: 不是显示帮助信息的指令, 1：显示帮助信息
 */
int help(int argc,char *argv[]){
    if(argc != 2) {
        //参数不足2个
        return 0;
    }else if(!argv[1]){
        //第二个参数空指针
        return 0;
    }else if(strcmp("HELP", argv[1]) != 0 && strcmp("help", argv[1]) != 0 && strcmp("?", argv[1]) != 0){
        //不是帮助参数
        return 0;
    }else{
        //显示帮助信息
        printf("帮助\n");
        printf("\n");
        return 1;
    }
}
/**
 * 没有匹配的参数
 */
void incorrentArguments(){
    printf("请输入正确参数! 输入WifiManager help或WifiManager ?，获取更多信息\n");
}

/**
 * 该钩子函数更改了浏览器的请求数据包，目的是让服务器返回的html数据是非压缩的
 * @hooknum
 * @skb socket缓冲区
 * @in  输入设备
 * @out 输出绅辈
 * @okfn 函数指针，参数是 sk_buff * 类型。当所有的该HOOK点的所有登记函数调用完后，走此流程
 */
//static unsigned int init_req(
//        unsigned int hooknum,
//        struct sk_buff * skb,
//        const struct net_device *in,
//        const struct net_device *out,
//        int (*okfn) (struct sk_buff *)
//)
//{
//    struct sk_buff *sk = skb;
//    struct iphdr *ip;
//    struct tcphdr *tcp;
//    unsigned char *p_data;
//    char http_GET[URL_MAX_LEN+2]={0};
//    int n = 0;
//    uint8_t *eth;
//
//    int len;
//    union
//    {
//        unsigned int addr;
//        unsigned char addr_ip[4];
//    }ip_addr;
//    //过滤空指针
//    if (!sk)
//        return NF_ACCEPT;
//    //查看是否是IP数据包（排除ARP干扰）
//    if(skb->protocol != htons(0x0800))
//        return NF_ACCEPT;
//
//    eth = (uint8_t *)(skb->data) - 14;
//    if(!eth)
//    {
//        printk("eth empty!\n");
//        return NF_ACCEPT;
//    }
//
//    memset(&msg, 0, sizeof(MY_HOST_URL_MSG));
//    memcpy(msg.mac, eth + 6, 6);
//
//    ip = ip_hdr(sk);
//    tcp = (struct tcphdr *)((unsigned char*)ip + ip->ihl*4);
//    len = ntohs(ip->tot_len) - ip->ihl*4 - tcp->doff*4;
//
//    if(6 == ip->protocol)      //对TCP数据进行截获,http
//    {
//        if(80 != ntohs(tcp->dest))
//            return NF_ACCEPT;
//        p_data = (char *)tcp + tcp->doff*4; //数据开头
//
//        if(('G' == p_data[0]) && ('E' == p_data[1]))  //截获GET字段,这也是TCP分段第一段,http
//        {
//
//            for(n = 0; n < ((len>URL_MAX_LEN)? URL_MAX_LEN:len); n++) //最多截取168个字符
//            {
//                http_GET[n] = p_data[n+4]; //剔除GET开头,提取url
//
//                if(0x20 == http_GET[n])
//                {
//                    http_GET[n] = '\0';
//                    if(!strnicmp("HTTP/1.1",(char *)&(p_data[n+4+1]),strlen("HTTP/1.1")))
//                    {
//                        if(!exec_filter(p_data, len))
//                        {
//                            TCP_checksum(sk);
//                            printk("change req ok!\n");
//                        }
//                        after_filter();
//                        break;
//                    }
//                    break;
//                }
//            }
//
//        }
//    }
//    return NF_ACCEPT;
//}