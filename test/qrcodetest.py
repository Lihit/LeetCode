from MyQR import myqr
import os
words=u"hello,world!"
version, level, qr_name = myqr.run(
    words,
    version=20,
    level='H',
    picture='test.jpg',
    colorized=True,
    contrast=1.0,
    brightness=1.0,
    save_name='hello.gif',
    save_dir=os.getcwd()
    )