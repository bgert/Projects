//
//  BMIC.swift
//  BMI
//
//  Created by Benjamin Gertz on 4/29/18.
//  Copyright © 2018 Benjamin Gertz. All rights reserved.
//

import Foundation

class BMIC {
    var height:Double
    var weight:Double
    let ret_string:String = "You are: "
    var bmi_r:Double = 0
    init (height:Double,weight:Double){
        self.height = height
        self.weight = weight
    }
    
    func bmi()->Double {
        let y = round(1000*((weight/(height * height)) * 703))/1000
        bmi_r = y
        return y
    }
    func classifier_label(bmi_result:Double)-> String {
        if bmi_r < 18.5 {
            return ret_string + "underweight. Please see a dietician about improving your diet."
        }
        if bmi_r < 25 {
            return ret_string + "normal."
        }
        if bmi_r < 30 {
            return ret_string + "overweight. Please see a dietician about improving your diet."
        }
        else {
            return ret_string + "obese. Please see a dietician about improving your diet."
        }
    }
}
