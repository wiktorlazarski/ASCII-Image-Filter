# ASCII Image Filter

The ASCII Image Filter is a console application that allows user to convert any given image, in _jpg_ format, to ASCII image, saved also in _jpg_ format. A path to input image should be given as first command line parameter and saving path of output image, within the name of created image included, should be passed as second command line parameter.

Application was writen in Microsoft Visual Studio 17, using _C++17_ standard and _OpenCV_ library.

## How to use

1) First you need to specify path where your __"ASCII filter.exe"__ file is located.
2) Specify input image location relative to folder where __"ASCII filter.exe"__ file is located.
3) Specify output image location relative to folder where __"ASCII filter.exe"__ file is located and name of output image.
4) Press _ENTER_.

#### General scheme

```cmd
<<app_folder_location>>/"ASCII filter.exe" <<input_folder_path>>/<<input_image_name>> <<output_folder_path>>/<<output_image_name>>
```

#### Example

```cmd
"./ASCII filter.exe" ./input.jpg output.jpg
```

![alt text](https://l3ipbw.db.files.1drv.com/y4mST4W3d4Wh0WtFsQlf1CZob-YJqowJn5n9NLoXGGtMXoNPNHtxZqTLevW8lJ_au6ZuMn_7ykcrormGBHY5hU2PIFx5Sw6UTkBsM1Dvbh1CjENJcd79sYFWd9V4PCORxIoeKM_9IuQQEWEOrhwrM6qbf_tnBqptNYg_oCFMp_3SvJwhRhWi8ZAX0w8uDTWBovbPlJZqQU5mP9W770kcCyM3Q/example.gif?download&psid=1)

## Example of filter outputs

| Original image  | Output ASCII image |
| ------------- | ------------- |
| ![alt text](https://db3pap002files.storage.live.com/y4m7TPjnot63HdDOG_EKOmgSiQMoH-cKBff5XuN8h94O_T2gTaFxLma_XoR1pq_4aneDU6YBpLM-jAKF62UFMMUNbQXH0gm9yKfBWifYEqmutzxrSLRWOnSQQJxQxkUeD9h8IZgKzz1wAkRIObcHaQklgmoYgd0M_AJEVQQCGO-y831rLzbYcGArf8sBY__c-2xhZXrpEJPrDSMbHRJzXPnig/example1.jpg?psid=1&width=224&height=224&cropMode=center)  | ![alt text](https://db3pap002files.storage.live.com/y4mhoBZ7MGBZorIHFk1ywaZ09oNQttF-UP22NaA1JLlFeHQImvJ8_4uR-0H4ndqV4NhN5H675MMUt04i8JRugvEbSXvHLwoP5mc2LKowNCAQVdqPc9eCI12IA3JCwOEnTR8oTnSDXxtGDLOCaRJP75ltfy2qkdPVp22sIxMT2rBMmQIKBD0IQVgJX-BaYXOLAIuf8BbcuvIhV1TqfALrWG-VA/outexample1.jpg?psid=1&width=224&height=324)  |
| ![alt text](https://db3pap002files.storage.live.com/y4mX51NhoMndhehNgPIyW7QZ-yqyPEhIBoYTAJs83zRQRCY18nK4_FoRpr9S-UB0JOtUmXh4KpocJrS0bCaiAdU_k9__QqMxSeOVxAvQZr24JZxJ79Qslt14qw2_lyNHbNvLskTyhrbNAuLYppT5EbUHgM_7dB_1ezpcmxNfBJASq3IO3OoHGGuGrRsauIX4kjPwZ7NLRbMrEwgSaP5FvKc6w/example2.jpg?psid=1&width=480&height=270)  | ![alt text](https://db3pap002files.storage.live.com/y4mh5gtc2YCh5T5XvzXP_xuMY8MTtgIg1DiVoCJj4jLuQUsv2ACO-_m9z231YODpDajKXsxGf9Uu83lvVNYZWSPdpX6CjlhSfnd4dSuaMp9W8GOGu05jyyRZzFxXWupABJVlnW_TSpgBM6LZ2UHxIwVw9W_H-HprSzfiKM5QQ9Ahjzm6Bb2cPtBpI9lcvTk_gXzldhK6zkuIOUNQpSH35yNjg/outexample2.jpg?psid=1&width=480&height=370)  |
| ![alt text](https://db3pap002files.storage.live.com/y4m9RiRwXMFOHT4Masjhj7M_D2i3zxKP-97XjbB-_mbWk7xgSXfoK0Ef2AZjvSTCswT6JZm7ph8Du2YmhXIse48Nn1GI3Jimt3JLwPZjIOIWKBsHliaBuAegimE8LzE2SZHTphdSbruaJd5bTMHaq0dzMX64LTlW6N9J6_EBergfM7vKrI5l3Mfx7Cf8mLN2bjZYofbUN68Bpil-1e5TztI_A/example3.jpg?psid=1&width=600&height=400)  | ![alt text](https://db3pap002files.storage.live.com/y4m05JsbHN6mapnXHoLh6WocgmuqZgTHS-u0UZLV12PldrV2qXEM3WWw_KF5EXW1RrsTHTBW0F7Y_GwgWUd_GfcGrQSDD3vyoTRN0BWJcgO2_5_fbySPHlsFh5Ckpo6gWBbR_0uLSGCa6FEga_M7Z-Qqd7PxcfKoySnn0p0f1Q8uSg5ZYbMZPNQ2VHRZxxDqA0wRHo654rHv66qzvjL3p859w/outexample3.jpg?psid=1&width=600&height=400)  |
| ![alt text](https://db3pap002files.storage.live.com/y4mOtNoPcnHjbdHK5j0gxQc3RauvzdCzBbZty3djmjn9ARlY4WG6PVR9JjBPN6boozUkiHPLnOtLESsW_WrS079uAWnMXjn7Zki15Wr6iwq5UZynb5yGmiM3zwBrZfxi_QXMvmAUQN7qIxTcS5nJUYk3dgw2-zA6LuEcEsOg1VC2ZV4dc1VILGZLNxE91-PHnpmvVm44JQSqejf2_rkMp4pzw/example4.jpg?psid=1&width=600&height=400)  | ![alt text](https://db3pap002files.storage.live.com/y4mjy_zqpf22sxdB778rcQMjN6PaKQybXWujf4IZUqKzj-k49IvrLuWy9HECO9ly-WemtwBQzkCYmMrt1J9JwxRpz1pvt-WAxZkzF9YAGZpj5zYTq3aWzUyOBRozmID5B5Ic05xV4wJVspagq7kmQiQG4PaBcVpc7v1h-vgTcPTYbO7HOJeYIBx-ey7rZfi3P5hEB7kTMZqukV-Akw3BxLdAA/outexample4.jpg?psid=1&width=600&height=400)  |
| ![alt text](https://db3pap002files.storage.live.com/y4mqF1_XArl-HcGqnGahDFrfWG7gCqzrNin5USUXREeK-99sdXfaOhv0E_Y3SHLq_r4NNe3Thrzpl7H5OSSQr2XDPuIMw440wvi0s-OrIK24vuvmyiMk-47X21TF0TB8_O-WSdZty5PF9BHHSVYJM0Xrp2_a1eBz3ZWHHG6UJthFAGiCbaLZJ28BvQfV7CsNQzImXMslqtpHyf6DchSeHBfTg/example5.jpg?psid=1&width=600&height=800)  | ![alt text](https://db3pap002files.storage.live.com/y4mkp6uhI5GvPlHlj3N3NfpERZ70cS5Yc6lnnwVJdvCXx3RJu8m5FcBVQcyPYx-p1vawuP3_RzSyhfUfCyk7kE90QztOZbZAu2BTRTR1-ey9t21xhhz5udMcpyoFjlXDb8rYGt6b-FUVb1wM8xu1KQi8xXzNw0-ifUd5ZM7YiEIwkG_SUiIB_ePx9sPYOpkv2L6LuMgYb7rR9ttBmWJeNw5DA/outexample5.jpg?psid=1&width=600&height=800)  |


#### Final remark
I am well awere that some functionalities which I implemented are already build-in OpenCV library (like for example converting RGB image to grayscale image). However, due to a fact that it is my first project involving image processing I wanted to practise and implement them by myself. Also what I wanted to practise is multithread programming in _Modern C++_.

Please send me info about any bug you spotted.</br>
email : wjlazarski@gmail.com
