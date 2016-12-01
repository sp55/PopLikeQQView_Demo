//
//  ViewController.m
//  PopLikeQQView_Demo
//
//  Created by admin on 2016/12/1.
//  Copyright © 2016年 AlezJi. All rights reserved.
//

#import "ViewController.h"

#import "PopLikeQQView.h"

#define TITLES @[@"修改", @"删除", @"扫一扫",@"付款"]
#define ICONS  @[@"motify",@"delete",@"saoyisao",@"pay"]


@interface ViewController ()<PopupMenuDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  
}
- (IBAction)btnAction:(id)sender {
    [PopLikeQQView showRelyOnView:sender titles:TITLES icons:ICONS menuWidth:120 delegate:self];

}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *t = touches.anyObject;
    CGPoint p = [t locationInView: self.view];
    
    PopLikeQQView *popupMenu = [PopLikeQQView showAtPoint:p titles:TITLES icons:nil menuWidth:110 delegate:nil];
    popupMenu.dismissOnSelected = NO;
    popupMenu.isShowShadow = YES;
    popupMenu.delegate = self;
    popupMenu.offset = 10;
    popupMenu.type = PopupMenuTypeDark;
}


#pragma mark - PopupMenuDelegate
- (void)popupMenuDidSelectedAtIndex:(NSInteger)index popupMenu:(PopLikeQQView *)popupMenu
{
    NSLog(@"点击了 %@ 选项",TITLES[index]);
}


@end
