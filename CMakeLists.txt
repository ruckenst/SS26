cmake_minimum_required(VERSION 3.30)
project(SS26)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS26
        main.cpp
        FeeStrategy.h
        PayPalFeeStrategy.cpp
        PayPalFeeStrategy.h
        TransferFeeStrategy.cpp
        TransferFeeStrategy.h
        MasterCardFeeStrategy.cpp
        MasterCardFeeStrategy.h
        FeeStrategyFactory.cpp
        FeeStrategyFactory.h
        PaymentRequest.cpp
        PaymentRequest.h
        PaymentProvider.h
        PaymentHandler.cpp
        PaymentHandler.h
        PaymentStartedHandler.cpp
        PaymentStartedHandler.h
        PaymentFinishedHandler.cpp
        PaymentFinishedHandler.h
        PaymentProcessingHandler.cpp
        PaymentProcessingHandler.h
)