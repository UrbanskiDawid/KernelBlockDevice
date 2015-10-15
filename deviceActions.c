#define DATA_MAXLEN 254

struct sDane {
  char input[DATA_MAXLEN];
  bool done;
} DATA;

static ssize_t devRead(struct file *f, char __user *buf, size_t len, loff_t *off)
{
  int l;
  static char napis[DATA_MAXLEN+20];

  sprintf(napis,"dawid memory: '%s'\n", DATA.input);
  l=strlen(napis);
  if(l>=len) return -EFAULT;

  if(*off!=0) return 0;

  if (copy_to_user(buf, &napis, l) != 0) return -EFAULT;
  *off=l;

  return l;
}

static ssize_t devWrite(struct file *f, const char *page,  size_t len, loff_t *offset)
{
  ssize_t bytes;
  if(len >= DATA_MAXLEN) return -EFAULT;
  bytes=len;

  printk(KERN_ALERT "in gdev_write\n");
  memset (DATA.input,0,sizeof(DATA.input));
  if(copy_from_user(DATA.input, page, bytes))  return bytes;

  return len;
}

static struct file_operations fops =
{
  .owner = THIS_MODULE,
  .read  = devRead,
  .write = devWrite
};
