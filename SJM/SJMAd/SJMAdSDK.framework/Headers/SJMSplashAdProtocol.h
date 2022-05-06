//
//  SJMSplashAdProtocol.h
//  SJMAdSDK
//
//  Created by Rare on 2020/12/22.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "SJMSplashAdProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@protocol SJMSplashAdProtocol <NSObject>

/**
 *  拉取广告超时时间，默认为3秒
 *  详解：拉取广告超时时间，开发者调用loadAd方法以后会立即展示backgroundImage，然后在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 */
@property (nonatomic, assign) CGFloat fetchDelay;

/**
 *  开屏广告的背景图片
 *  可以设置背景图片作为开屏加载时的默认背景
 */
@property (nonatomic, strong) UIImage *backgroundImage;


/// 用于处理广告动作的视图控制器
@property (nonatomic, weak) UIViewController *_Nullable rootViewController;


/**
 *  开屏广告的背景色
 *  可以设置开屏图片来作为开屏加载时的默认图片
 */
@property (nonatomic, copy) UIColor *backgroundColor;

@property(nonatomic,assign) CGSize bottomViewSize;

-(BOOL) isAdValid;
/**
*  发起拉取广告请求，只拉取不展示
*  详解：广告素材及广告图片拉取成功后会回调splashAdDidLoad方法，当拉取失败时会回调splashAdFailToPresent方法
*/
- (void) loadAd;

/**
 *  展示广告，调用此方法前需调用isAdValid方法判断广告素材是否有效
 *  详解：广告展示成功时会回调splashAdSuccessPresentScreen方法，展示失败时会回调splashAdFailToPresent方法
 */
- (void)showAdInWindow:(UIWindow *)window withBottomView:(nullable UIView *)bottomView;

@end

NS_ASSUME_NONNULL_END
