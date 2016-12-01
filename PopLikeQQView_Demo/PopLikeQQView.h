//
//  PopLikeQQView.h
//  PopLikeQQView_Demo
//
//  Created by admin on 2016/12/1.
//  Copyright © 2016年 AlezJi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger , PopupMenuType) {
    PopupMenuTypeDefault = 0,
    PopupMenuTypeDark
};

@class PopLikeQQView;
@protocol PopupMenuDelegate <NSObject>

@optional
/**
 点击事件回调
 */
- (void)popupMenuDidSelectedAtIndex:(NSInteger)index popupMenu:(PopLikeQQView *)popupMenu;

@end



@interface PopLikeQQView : UIView

/**
 圆角半径 Default is 5.0
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 是否显示阴影 Default is YES
 */
@property (nonatomic, assign , getter=isShadowShowing) BOOL isShowShadow;

/**
 选择菜单项后消失 Default is YES
 */
@property (nonatomic, assign) BOOL dismissOnSelected;

/**
 点击菜单外消失  Default is YES
 */
@property (nonatomic, assign) BOOL dismissOnTouchOutside;

/**
 设置字体大小 Default is 15
 */
@property (nonatomic, assign) CGFloat fontSize;

/**
 设置字体颜色 Default is [UIColor blackColor]
 */
@property (nonatomic, strong) UIColor * textColor;

/**
 设置偏移距离 (>= 0) Default is 0.0
 */
@property (nonatomic, assign) CGFloat offset;

/**
 设置显示模式 Default is YBPopupMenuTypeDefault
 */
@property (nonatomic, assign) PopupMenuType type;

/**
 代理
 */
@property (nonatomic, weak) id <PopupMenuDelegate> delegate;

/**
 在指定位置弹出类方法
 
 @param titles    标题数组
 @param icons     图标数组
 @param itemWidth 菜单宽度
 @param delegate  代理
 */
+ (instancetype)showAtPoint:(CGPoint)point
                     titles:(NSArray *)titles
                      icons:(NSArray *)icons
                  menuWidth:(CGFloat)itemWidth
                   delegate:(id<PopupMenuDelegate>)delegate;


/**
 依赖指定view弹出类方法
 
 @param titles    标题数组
 @param icons     图标数组
 @param itemWidth 菜单宽度
 @param delegate  代理
 */
+ (instancetype)showRelyOnView:(UIView *)view
                        titles:(NSArray *)titles
                         icons:(NSArray *)icons
                     menuWidth:(CGFloat)itemWidth
                      delegate:(id<PopupMenuDelegate>)delegate;

/**
 消失
 */
- (void)dismiss;

@end
