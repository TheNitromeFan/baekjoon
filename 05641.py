import sys


table = {3500: 217, 3501: 169, 3502: 7, 3503: 37, 3504: 391, 3505: 607, 3506: 97, 3507: 49, 3508: 19, 3509: 37, 3510: 31, 3511: 667, 3512: 91, 3513: 97, 3514: 37, 3515: 61, 3516: 169, 3517: 229, 3518: 271, 3519: 907, 3520: 7, 3521: 7, 3522: 187, 3523: 91, 3524: 97, 3525: 211, 3526: 19, 3527: 79, 3528: 211, 3529: 61, 3530: 97, 3531: 169, 3532: 697, 3533: 37, 3534: 97, 3535: 799, 3536: 337, 3537: 7, 3538: 247, 3539: 97, 3540: 349, 3541: 169, 3542: 97, 3543: 37, 3544: 217, 3545: 121, 3546: 151, 3547: 7, 3548: 49, 3549: 127, 3550: 19, 3551: 97, 3552: 19, 3553: 37, 3554: 169, 3555: 7, 3556: 187, 3557: 7, 3558: 151, 3559: 7, 3560: 169, 3561: 247, 3562: 217, 3563: 289, 3564: 127, 3565: 7, 3566: 31, 3567: 37, 3568: 31, 3569: 331, 3570: 391, 3571: 7, 3572: 49, 3573: 259, 3574: 61, 3575: 79, 3576: 127, 3577: 157, 3578: 7, 3579: 127, 3580: 7, 3581: 7, 3582: 97, 3583: 577, 3584: 259, 3585: 37, 3586: 487, 3587: 271, 3588: 481, 3589: 499, 3590: 31, 3591: 559, 3592: 121, 3593: 79, 3594: 211, 3595: 121, 3596: 127, 3597: 37, 3598: 7, 3599: 97, 3600: 517, 3601: 157, 3602: 511, 3603: 7, 3604: 19, 3605: 271, 3606: 151, 3607: 169, 3608: 649, 3609: 7, 3610: 7, 3611: 121, 3612: 349, 3613: 37, 3614: 127, 3615: 169, 3616: 19, 3617: 7, 3618: 271, 3619: 61, 3620: 49, 3621: 361, 3622: 361, 3623: 181, 3624: 169, 3625: 211, 3626: 19, 3627: 427, 3628: 49, 3629: 289, 3630: 577, 3631: 187, 3632: 91, 3633: 7, 3634: 229, 3635: 79, 3636: 151, 3637: 211, 3638: 511, 3639: 37, 3640: 409, 3641: 331, 3642: 547, 3643: 199, 3644: 91, 3645: 49, 3646: 49, 3647: 187, 3648: 31, 3649: 211, 3650: 169, 3651: 169, 3652: 61, 3653: 61, 3654: 19, 3655: 79, 3656: 91, 3657: 181, 3658: 319, 3659: 7, 3660: 169, 3661: 271, 3662: 7, 3663: 79, 3664: 31, 3665: 277, 3666: 337, 3667: 7, 3668: 97, 3669: 127, 3670: 301, 3671: 7, 3672: 151, 3673: 31, 3674: 31, 3675: 211, 3676: 187, 3677: 271, 3678: 97, 3679: 169, 3680: 7, 3681: 1, 3682: 19, 3683: 97, 3684: 151, 3685: 37, 3686: 259, 3687: 697, 3688: 7, 3689: 61, 3690: 31, 3691: 211, 3692: 187, 3693: 7, 3694: 49, 3695: 61, 3696: 271, 3697: 187, 3698: 589, 3699: 7, 3700: 451, 3701: 37, 3702: 547, 3703: 451, 3704: 409, 3705: 97, 3706: 289, 3707: 499, 3708: 127, 3709: 229, 3710: 49, 3711: 49, 3712: 1087, 3713: 61, 3714: 31, 3715: 61, 3716: 349, 3717: 91, 3718: 319, 3719: 37, 3720: 391, 3721: 229, 3722: 271, 3723: 7, 3724: 499, 3725: 67, 3726: 151, 3727: 199, 3728: 409, 3729: 1327, 3730: 247, 3731: 271, 3732: 517, 3733: 37, 3734: 7, 3735: 37, 3736: 7, 3737: 97, 3738: 31, 3739: 61, 3740: 49, 3741: 1351, 3742: 37, 3743: 37, 3744: 349, 3745: 61, 3746: 169, 3747: 127, 3748: 427, 3749: 139, 3750: 361, 3751: 157, 3752: 217, 3753: 127, 3754: 49, 3755: 61, 3756: 127, 3757: 7, 3758: 181, 3759: 259, 3760: 7, 3761: 61, 3762: 19, 3763: 31, 3764: 1279, 3765: 211, 3766: 31, 3767: 79, 3768: 391, 3769: 37, 3770: 139, 3771: 127, 3772: 19, 3773: 79, 3774: 151, 3775: 91, 3776: 187, 3777: 37, 3778: 19, 3779: 7, 3780: 31, 3781: 397, 3782: 379, 3783: 697, 3784: 31, 3785: 79, 3786: 31, 3787: 169, 3788: 91, 3789: 37, 3790: 7, 3791: 121, 3792: 151, 3793: 37, 3794: 97, 3795: 139, 3796: 19, 3797: 67, 3798: 19, 3799: 61, 3800: 229, 3801: 91, 3802: 19, 3803: 79, 3804: 169, 3805: 61, 3806: 49, 3807: 421, 3808: 19, 3809: 7, 3810: 349, 3811: 7, 3812: 49, 3813: 259, 3814: 61, 3815: 37, 3816: 229, 3817: 157, 3818: 31, 3819: 289, 3820: 49, 3821: 61, 3822: 367, 3823: 31, 3824: 127, 3825: 91, 3826: 31, 3827: 79, 3828: 19, 3829: 7, 3830: 31, 3831: 7, 3832: 499, 3833: 7, 3834: 97, 3835: 31, 3836: 61, 3837: 127, 3838: 427, 3839: 61, 3840: 151, 3841: 7, 3842: 349, 3843: 1147, 3844: 19, 3845: 7, 3846: 151, 3847: 61, 3848: 181, 3849: 247, 3850: 607, 3851: 61, 3852: 127, 3853: 79, 3854: 169, 3855: 91, 3856: 19, 3857: 37, 3858: 31, 3859: 7, 3860: 31, 3861: 127, 3862: 19, 3863: 271, 3864: 277, 3865: 79, 3866: 217, 3867: 7, 3868: 7, 3869: 331, 3870: 97, 3871: 31, 3872: 187, 3873: 49, 3874: 31, 3875: 7, 3876: 151, 3877: 157, 3878: 49, 3879: 37, 3880: 217, 3881: 91, 3882: 19, 3883: 121, 3884: 127, 3885: 37, 3886: 151, 3887: 427, 3888: 151, 3889: 61, 3890: 49, 3891: 91, 3892: 451, 3893: 301, 3894: 211, 3895: 157, 3896: 31, 3897: 37, 3898: 247, 3899: 139, 3900: 169, 3901: 289, 3902: 187, 3903: 259, 3904: 91, 3905: 37, 3906: 337, 3907: 7, 3908: 19, 3909: 169, 3910: 541, 3911: 61, 3912: 271, 3913: 421, 3914: 31, 3915: 91, 3916: 91, 3917: 79, 3918: 337, 3919: 37, 3920: 31, 3921: 211, 3922: 37, 3923: 961, 3924: 151, 3925: 787, 3926: 169, 3927: 49, 3928: 247, 3929: 37, 3930: 181, 3931: 169, 3932: 49, 3933: 91, 3934: 217, 3935: 79, 3936: 169, 3937: 37, 3938: 31, 3939: 49, 3940: 31, 3941: 7, 3942: 151, 3943: 79, 3944: 127, 3945: 361, 3946: 289, 3947: 7, 3948: 151, 3949: 301, 3950: 169, 3951: 259, 3952: 217, 3953: 7, 3954: 151, 3955: 397, 3956: 19, 3957: 97, 3958: 481, 3959: 7, 3960: 229, 3961: 211, 3962: 97, 3963: 361, 3964: 91, 3965: 7, 3966: 19, 3967: 121, 3968: 91, 3969: 91, 3970: 361, 3971: 277, 3972: 187, 3973: 157, 3974: 7, 3975: 7, 3976: 217, 3977: 79, 3978: 391, 3979: 7, 3980: 19, 3981: 91, 3982: 49, 3983: 601, 3984: 421, 3985: 7, 3986: 31, 3987: 127, 3988: 31, 3989: 121, 3990: 97, 3991: 7, 3992: 91, 3993: 211, 3994: 289, 3995: 61, 3996: 361, 3997: 61, 3998: 31, 3999: 97, 4000: 31, 4001: 121, 4002: 97, 4003: 229, 4004: 259, 4005: 49, 4006: 7, 4007: 37, 4008: 211, 4009: 91, 4010: 97, 4011: 139, 4012: 61, 4013: 181, 4014: 577, 4015: 121, 4016: 31, 4017: 391, 4018: 37, 4019: 61, 4020: 367, 4021: 229, 4022: 7, 4023: 181, 4024: 31, 4025: 61, 4026: 169, 4027: 7, 4028: 7, 4029: 127, 4030: 7, 4031: 67, 4032: 151, 4033: 7, 4034: 97, 4035: 49, 4036: 31, 4037: 187, 4038: 97, 4039: 37, 4040: 217, 4041: 7, 4042: 289, 4043: 277, 4044: 19, 4045: 79, 4046: 49, 4047: 127, 4048: 7, 4049: 79, 4050: 271, 4051: 397, 4052: 379, 4053: 7, 4054: 37, 4055: 181, 4056: 151, 4057: 187, 4058: 217, 4059: 127, 4060: 247, 4061: 61, 4062: 127, 4063: 37, 4064: 127, 4065: 37, 4066: 217, 4067: 1189, 4068: 31, 4069: 577, 4070: 409, 4071: 169, 4072: 511, 4073: 739, 4074: 97, 4075: 211, 4076: 49, 4077: 7, 4078: 19, 4079: 121, 4080: 349, 4081: 37, 4082: 169, 4083: 7, 4084: 61, 4085: 37, 4086: 19, 4087: 169, 4088: 181, 4089: 49, 4090: 49, 4091: 61, 4092: 517, 4093: 7, 4094: 181, 4095: 49, 4096: 19, 4097: 7, 4098: 409, 4099: 169, 4100: 451, 4101: 289, 4102: 289, 4103: 61, 4104: 31, 4105: 121, 4106: 421, 4107: 97, 4108: 61, 4109: 67, 4110: 31, 4111: 91, 4112: 91, 4113: 127, 4114: 49, 4115: 7, 4116: 31, 4117: 7, 4118: 7, 4119: 7, 4120: 19, 4121: 139, 4122: 181, 4123: 91, 4124: 91, 4125: 799, 4126: 187, 4127: 37, 4128: 97, 4129: 61, 4130: 337, 4131: 169, 4132: 7, 4133: 271, 4134: 277, 4135: 79, 4136: 187, 4137: 211, 4138: 121, 4139: 259, 4140: 211, 4141: 7, 4142: 61, 4143: 97, 4144: 151, 4145: 7, 4146: 151, 4147: 61, 4148: 7, 4149: 91, 4150: 61, 4151: 97, 4152: 169, 4153: 37, 4154: 427, 4155: 97, 4156: 19, 4157: 511, 4158: 31, 4159: 541, 4160: 607, 4161: 319, 4162: 37, 4163: 7, 4164: 19, 4165: 37, 4166: 169, 4167: 541, 4168: 247, 4169: 121, 4170: 811, 4171: 7, 4172: 271, 4173: 49, 4174: 7, 4175: 37, 4176: 229, 4177: 247, 4178: 181, 4179: 49, 4180: 49, 4181: 139, 4182: 169, 4183: 31, 4184: 7, 4185: 391, 4186: 187, 4187: 97, 4188: 277, 4189: 61, 4190: 169, 4191: 139, 4192: 271, 4193: 97, 4194: 229, 4195: 79, 4196: 19, 4197: 37, 4198: 301, 4199: 79, 4200: 181, 4201: 37, 4202: 169, 4203: 127, 4204: 319, 4205: 139, 4206: 31, 4207: 169, 4208: 7, 4209: 331, 4210: 247, 4211: 499, 4212: 19, 4213: 91, 4214: 49, 4215: 181, 4216: 151, 4217: 7, 4218: 31, 4219: 7, 4220: 7, 4221: 7, 4222: 61, 4223: 37, 4224: 211, 4225: 7, 4226: 49, 4227: 7, 4228: 7, 4229: 61, 4230: 361, 4231: 169, 4232: 169, 4233: 127, 4234: 217, 4235: 67, 4236: 169, 4237: 247, 4238: 49, 4239: 127, 4240: 319, 4241: 91, 4242: 19, 4243: 199, 4244: 49, 4245: 427, 4246: 151, 4247: 139, 4248: 19, 4249: 499, 4250: 31, 4251: 7, 4252: 37, 4253: 37, 4254: 19, 4255: 61, 4256: 19, 4257: 37, 4258: 49, 4259: 7, 4260: 349, 4261: 7, 4262: 7, 4263: 259, 4264: 31, 4265: 7, 4266: 31, 4267: 157, 4268: 91, 4269: 127, 4270: 451, 4271: 97, 4272: 697, 4273: 61, 4274: 139, 4275: 7, 4276: 19, 4277: 271, 4278: 97, 4279: 451, 4280: 31, 4281: 127, 4282: 301, 4283: 79, 4284: 349, 4285: 7, 4286: 169, 4287: 97, 4288: 289, 4289: 37, 4290: 97, 4291: 397, 4292: 91, 4293: 49, 4294: 361, 4295: 277, 4296: 127, 4297: 37, 4298: 31, 4299: 541, 4300: 151, 4301: 37, 4302: 127, 4303: 121, 4304: 61, 4305: 181, 4306: 37, 4307: 91, 4308: 97, 4309: 7, 4310: 7, 4311: 259, 4312: 7, 4313: 79, 4314: 277, 4315: 91, 4316: 169, 4317: 7, 4318: 7, 4319: 277, 4320: 181, 4321: 469, 4322: 217, 4323: 91, 4324: 19, 4325: 37, 4326: 151, 4327: 7, 4328: 337, 4329: 421, 4330: 19, 4331: 121, 4332: 127, 4333: 229, 4334: 97, 4335: 37, 4336: 19, 4337: 139, 4338: 97, 4339: 7, 4340: 49, 4341: 361, 4342: 217, 4343: 7, 4344: 31, 4345: 31, 4346: 349, 4347: 139, 4348: 289, 4349: 79, 4350: 97, 4351: 229, 4352: 7, 4353: 361, 4354: 37, 4355: 277, 4356: 151, 4357: 211, 4358: 49, 4359: 37, 4360: 277, 4361: 61, 4362: 391, 4363: 31, 4364: 229, 4365: 79, 4366: 709, 4367: 79, 4368: 1117, 4369: 379, 4370: 187, 4371: 127, 4372: 121, 4373: 529, 4374: 31, 4375: 211, 4376: 19, 4377: 97, 4378: 427, 4379: 121, 4380: 229, 4381: 31, 4382: 139, 4383: 37, 4384: 61, 4385: 121, 4386: 151, 4387: 61, 4388: 31, 4389: 127, 4390: 61, 4391: 7, 4392: 349, 4393: 121, 4394: 49, 4395: 91, 4396: 151, 4397: 97, 4398: 127, 4399: 169, 4400: 337, 4401: 7, 4402: 247, 4403: 97, 4404: 31, 4405: 169, 4406: 31, 4407: 361, 4408: 217, 4409: 37, 4410: 97, 4411: 31, 4412: 169, 4413: 289, 4414: 19, 4415: 61, 4416: 31, 4417: 37, 4418: 49, 4419: 259, 4420: 7, 4421: 7, 4422: 211, 4423: 79, 4424: 259, 4425: 37, 4426: 319, 4427: 271, 4428: 19, 4429: 7, 4430: 271, 4431: 361, 4432: 541, 4433: 331, 4434: 151, 4435: 211, 4436: 91, 4437: 37, 4438: 7, 4439: 61, 4440: 31, 4441: 631, 4442: 181, 4443: 127, 4444: 691, 4445: 61, 4446: 181, 4447: 331, 4448: 19, 4449: 1, 4450: 229, 4451: 301, 4452: 19, 4453: 7, 4454: 7, 4455: 169, 4456: 31, 4457: 7, 4458: 277, 4459: 577, 4460: 49, 4461: 127, 4462: 289, 4463: 271, 4464: 151, 4465: 211, 4466: 229, 4467: 127, 4468: 481, 4469: 37, 4470: 97, 4471: 301, 4472: 7, 4473: 709, 4474: 277, 4475: 79, 4476: 127, 4477: 37, 4478: 49, 4479: 361, 4480: 361, 4481: 259, 4482: 97, 4483: 7, 4484: 127, 4485: 139, 4486: 709, 4487: 37, 4488: 127, 4489: 79, 4490: 49, 4491: 169, 4492: 187, 4493: 79, 4494: 97, 4495: 397, 4496: 451, 4497: 319, 4498: 607, 4499: 61, 4500: 271, 4501: 91, 4502: 187, 4503: 211, 4504: 619, 4505: 97, 4506: 391, 4507: 7, 4508: 19, 4509: 49, 4510: 61, 4511: 61, 4512: 169, 4513: 331, 4514: 97, 4515: 91, 4516: 91, 4517: 7, 4518: 271, 4519: 31, 4520: 271, 4521: 427, 4522: 37, 4523: 91, 4524: 349, 4525: 79, 4526: 7, 4527: 49, 4528: 19, 4529: 7, 4530: 31, 4531: 469, 4532: 97, 4533: 127, 4534: 7, 4535: 7, 4536: 187, 4537: 79, 4538: 49, 4539: 331, 4540: 19, 4541: 559, 4542: 97, 4543: 229, 4544: 169, 4545: 139, 4546: 187, 4547: 499, 4548: 31, 4549: 229, 4550: 19, 4551: 247, 4552: 7, 4553: 61, 4554: 31, 4555: 271, 4556: 19, 4557: 91, 4558: 49, 4559: 91, 4560: 169, 4561: 37, 4562: 409, 4563: 79, 4564: 7, 4565: 271, 4566: 31, 4567: 61, 4568: 127, 4569: 337, 4570: 37, 4571: 97, 4572: 151, 4573: 331, 4574: 181, 4575: 49, 4576: 187, 4577: 121, 4578: 19, 4579: 229, 4580: 169, 4581: 7, 4582: 499, 4583: 301, 4584: 337, 4585: 37, 4586: 7, 4587: 337, 4588: 61, 4589: 181, 4590: 349, 4591: 157, 4592: 61, 4593: 49, 4594: 289, 4595: 319, 4596: 277, 4597: 427, 4598: 31, 4599: 259, 4600: 187, 4601: 607, 4602: 97, 4603: 499, 4604: 169, 4605: 37, 4606: 19, 4607: 97, 4608: 817, 4609: 397, 4610: 49, 4611: 7, 4612: 49, 4613: 7, 4614: 97, 4615: 31, 4616: 217, 4617: 7, 4618: 217, 4619: 61, 4620: 181, 4621: 187, 4622: 7, 4623: 37, 4624: 289, 4625: 79, 4626: 811, 4627: 157, 4628: 31, 4629: 49, 4630: 427, 4631: 457, 4632: 19, 4633: 91, 4634: 7, 4635: 139, 4636: 7, 4637: 37, 4638: 151, 4639: 121, 4640: 91, 4641: 361, 4642: 121, 4643: 727, 4644: 19, 4645: 397, 4646: 301, 4647: 181, 4648: 361, 4649: 7, 4650: 391, 4651: 7, 4652: 271, 4653: 79, 4654: 61, 4655: 277, 4656: 187, 4657: 7, 4658: 19, 4659: 127, 4660: 19, 4661: 97, 4662: 19, 4663: 7, 4664: 259, 4665: 757, 4666: 31, 4667: 97, 4668: 409, 4669: 7, 4670: 19, 4671: 169, 4672: 19, 4673: 79, 4674: 151, 4675: 61, 4676: 31, 4677: 211, 4678: 1069, 4679: 61, 4680: 517, 4681: 7, 4682: 97, 4683: 361, 4684: 151, 4685: 511, 4686: 151, 4687: 37, 4688: 127, 4689: 127, 4690: 301, 4691: 271, 4692: 127, 4693: 271, 4694: 379, 4695: 49, 4696: 19, 4697: 181, 4698: 97, 4699: 499, 4700: 271, 4701: 127, 4702: 187, 4703: 61, 4704: 151, 4705: 61, 4706: 169, 4707: 517, 4708: 19, 4709: 139, 4710: 409, 4711: 157, 4712: 7, 4713: 247, 4714: 121, 4715: 499, 4716: 229, 4717: 61, 4718: 511, 4719: 49, 4720: 31, 4721: 37, 4722: 559, 4723: 31, 4724: 7, 4725: 139, 4726: 289, 4727: 79, 4728: 19, 4729: 61, 4730: 169, 4731: 211, 4732: 61, 4733: 79, 4734: 391, 4735: 91, 4736: 19, 4737: 97, 4738: 487, 4739: 97, 4740: 151, 4741: 427, 4742: 7, 4743: 37, 4744: 319, 4745: 667, 4746: 31, 4747: 61, 4748: 127, 4749: 247, 4750: 271, 4751: 61, 4752: 127, 4753: 121, 4754: 181, 4755: 49, 4756: 19, 4757: 67, 4758: 409, 4759: 577, 4760: 451, 4761: 259, 4762: 247, 4763: 61, 4764: 169, 4765: 7, 4766: 7, 4767: 97, 4768: 7, 4769: 7, 4770: 181, 4771: 397, 4772: 217, 4773: 97, 4774: 19, 4775: 61, 4776: 127, 4777: 79, 4778: 31, 4779: 127, 4780: 49, 4781: 7, 4782: 97, 4783: 271, 4784: 421, 4785: 259, 4786: 187, 4787: 649, 4788: 19, 4789: 211, 4790: 139, 4791: 7, 4792: 217, 4793: 97, 4794: 169, 4795: 31, 4796: 19, 4797: 331, 4798: 247, 4799: 97, 4800: 31, 4801: 157, 4802: 217, 4803: 517, 4804: 877, 4805: 7, 4806: 211, 4807: 61, 4808: 127, 4809: 757, 4810: 301, 4811: 187, 4812: 151, 4813: 37, 4814: 49, 4815: 79, 4816: 217, 4817: 7, 4818: 31, 4819: 619, 4820: 49, 4821: 49, 4822: 37, 4823: 271, 4824: 151, 4825: 331, 4826: 19, 4827: 91, 4828: 61, 4829: 289, 4830: 181, 4831: 271, 4832: 7, 4833: 49, 4834: 289, 4835: 61, 4836: 127, 4837: 7, 4838: 97, 4839: 391, 4840: 19, 4841: 7, 4842: 19, 4843: 157, 4844: 421, 4845: 391, 4846: 31, 4847: 37, 4848: 31, 4849: 451, 4850: 31, 4851: 91, 4852: 7, 4853: 271, 4854: 391, 4855: 121, 4856: 91, 4857: 427, 4858: 7, 4859: 7, 4860: 349, 4861: 91, 4862: 559, 4863: 331, 4864: 61, 4865: 37, 4866: 367, 4867: 169, 4868: 481, 4869: 37, 4870: 61, 4871: 7, 4872: 19, 4873: 61, 4874: 607, 4875: 259, 4876: 91, 4877: 7, 4878: 151, 4879: 169, 4880: 217, 4881: 7, 4882: 289, 4883: 649, 4884: 97, 4885: 31, 4886: 481, 4887: 139, 4888: 481, 4889: 37, 4890: 97, 4891: 301, 4892: 169, 4893: 91, 4894: 121, 4895: 79, 4896: 31, 4897: 7, 4898: 49, 4899: 97, 4900: 19, 4901: 67, 4902: 151, 4903: 79, 4904: 127, 4905: 37, 4906: 49, 4907: 1111, 4908: 1237, 4909: 37, 4910: 7, 4911: 289, 4912: 7, 4913: 511, 4914: 811, 4915: 79, 4916: 61, 4917: 247, 4918: 511, 4919: 61, 4920: 271, 4921: 7, 4922: 217, 4923: 127, 4924: 481, 4925: 79, 4926: 127, 4927: 157, 4928: 301, 4929: 37, 4930: 301, 4931: 331, 4932: 577, 4933: 7, 4934: 31, 4935: 169, 4936: 19, 4937: 7, 4938: 19, 4939: 31, 4940: 187, 4941: 127, 4942: 19, 4943: 139, 4944: 151, 4945: 61, 4946: 49, 4947: 97, 4948: 7, 4949: 391, 4950: 211, 4951: 157, 4952: 847, 4953: 211, 4954: 49, 4955: 7, 4956: 151, 4957: 397, 4958: 127, 4959: 37, 4960: 19, 4961: 391, 4962: 97, 4963: 61, 4964: 127, 4965: 37, 4966: 151, 4967: 7, 4968: 19, 4969: 247, 4970: 19, 4971: 361, 4972: 427, 4973: 79, 4974: 277, 4975: 91, 4976: 229, 4977: 7, 4978: 451, 4979: 277, 4980: 97, 4981: 7, 4982: 97, 4983: 181, 4984: 217, 4985: 97, 4986: 211, 4987: 61, 4988: 19, 4989: 391, 4990: 37, 4991: 67, 4992: 181, 4993: 37, 4994: 31, 4995: 259, 4996: 19, 4997: 37, 4998: 337, 4999: 301, 5000: 337}
while True:
    n = int(sys.stdin.readline().split()[0])
    if n == 0:
        break
    sys.stdout.write(f"{10 ** (n - 1) + table[n]}\n")
